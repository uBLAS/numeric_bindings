$TEMPLATE[template_lapack_solve]
    // uniform high-level dispatching-function
    template< typename MatrixA, typename MatrixB, typename VectorP >
    static void solve( MatrixA& A, MatrixB& B, VectorP& pivot, integer_t& info ) {
        invoke( $KEYWORDS );
    }
$TEMPLATE[end]
