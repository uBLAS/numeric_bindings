/*
 *
 * Copyright (c) Kresimir Fresl 2003
 * Copyright (c) 2010 Thomas Klimpel
 *
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 *
 * Author acknowledges the support of the Faculty of Civil Engineering,
 * University of Zagreb, Croatia.
 *
 */

#ifndef BOOST_NUMERIC_BINDINGS_TRAITS_DETAIL_UTILS_HPP
#define BOOST_NUMERIC_BINDINGS_TRAITS_DETAIL_UTILS_HPP

#include <iterator>
#include <boost/numeric/bindings/traits/type_traits.hpp>

namespace boost { namespace numeric { namespace bindings { namespace traits {

  namespace detail {

    // complex array => real & imaginary arrays
    template <typename CIt, typename RIt>
    void disentangle (CIt c, CIt c_end, RIt rr, RIt ri) {
      for (; c != c_end; ++c, ++rr, ++ri) {
        *rr = traits::real (*c); 
        *ri = traits::imag (*c); 
      }
    }
    // real & imaginary arrays => complex array
    template <typename RIt, typename CIt>
    void interlace (RIt r, RIt r_end, RIt ri, CIt c) {
      typedef typename std::iterator_traits<CIt>::value_type cmplx_t;
#ifdef BOOST_NUMERIC_BINDINGS_BY_THE_BOOK
      for (; r != r_end; ++r, ++ri, ++c)
        *c = cmplx_t (*r, *ri);
#else
      typedef typename type_traits<cmplx_t>::real_type real_t;
      real_t *cp = reinterpret_cast<real_t*> (&*c);
      for (; r != r_end; ++r, ++ri) {
        *cp = *r; ++cp;
        *cp = *ri; ++cp;
      }
#endif
    }

#ifdef BOOST_NUMERIC_BINDINGS_BY_THE_BOOK
    template <typename It>
    void inshuffle(It it, std::size_t n) {
      if (n==0) return;
      for (std::size_t i = 0; 2*i < n; ++i) {
        std::size_t k = 2*i + 1;
        while (2*k <= n) k *= 2;
        typename std::iterator_traits<It>::value_type tmp = it[n+i];
        it[n+i] = it[k-1];
        while (k % 2 == 0) {
          it[k-1] = it[(k/2)-1];
          k /= 2;
        }
        it[k-1] = tmp;
      }
      std::size_t kmin = 1;
      while (2*kmin <= n) kmin *= 2;
      for (std::size_t i = 0; 4*i+1 < n; ++i) {
        std::size_t k = 2*i + 1;
        while (2*k <= n) k *= 2;
        std::size_t k1 = 2*(i+1) + 1;
        while (2*k1 <= n) k1 *= 2;
        if (k > k1) {
          if (k1 < kmin) {
            kmin = k1;
            inshuffle(it+n, i+1);
          }
          else
            inshuffle(it+n+1, i);
        }
      }
      return inshuffle(it+n+(n%2), n/2);
    }
#else
    template <typename It>
    void inshuffle(It it, std::size_t n) {
      while (n > 0) {
        std::size_t kmin = 1;
        while (kmin <= n)
          kmin *= 2;
        {
          std::size_t kk = kmin/2;
          It itn = it + n;
          for (std::size_t i = 0, s = (n+1)/2; i < s; ++i) {
            std::size_t k = (2*i+1)*kk;
            while (k > n) {
              k /= 2;
              kk /= 2;
            }
            // apply the cyclic permutation
            typename std::iterator_traits<It>::value_type tmp = itn[i];
            itn[i] = it[k-1];
            while (k % 2 == 0) {
              it[k-1] = it[(k/2)-1];
              k /= 2;
            }
            it[k-1] = tmp;
          }
        }
        // the optimized computation of k fails for n=2,
        // so skip the 'normalization' loop when possible
        if (n > 3) {
          std::size_t kk = kmin/4;
          for (std::size_t i = 1; 4*i < n+3; ++i) {
            std::size_t k = (2*i+1)*kk;
            if (k > n) {
              kk /= 2;
              if (k < kmin) {
                kmin = k;
                // if kmin is updated, do an in-shuffle
                inshuffle(it+n, i);
              }
              else
                // otherwise do an out-shuffle
                inshuffle(it+n+1, i-1);
            }
          }
        }
        // implement the tail recursion as an iteration
        it += n+(n%2);
        n /= 2;
      }
    }
#endif

    // real & imaginary arrays => complex array
    template <typename CIt>
    void interlace (CIt c, std::ptrdiff_t n) {
      typedef typename std::iterator_traits<CIt>::value_type cmplx_t;
      typedef typename type_traits<cmplx_t>::real_type real_t;
      if (n < 2) return;
      inshuffle(reinterpret_cast<real_t*> (&*c)+1, n-1);
    }

    // converts real/complex to std::ptrdiff_t
    inline std::ptrdiff_t to_int (float f) { return static_cast<std::ptrdiff_t> (f); }
    inline std::ptrdiff_t to_int (double d) { return static_cast<std::ptrdiff_t> (d); }
    inline std::ptrdiff_t to_int (traits::complex_f const& cf) {
      return static_cast<std::ptrdiff_t> (traits::real (cf));
    }
    inline std::ptrdiff_t to_int (traits::complex_d const& cd) {
      return static_cast<std::ptrdiff_t> (traits::real (cd));
    }

  }

}}}}

#endif
