Problem:    1
Rows:       37
Columns:    47
Non-zeros:  150
Status:     UNDEFINED
Objective:  investimento = 0 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 inicioTardio B              0            -0             = 
     2 s1           B              0            -0             = 
     3 s2           B              0            -0             = 
     4 s3           B              0            -0             = 
     5 calcGasto[1] B              0            -0             = 
     6 calcGasto[2] B              0            -0             = 
     7 calcGasto[3] B              0            -0             = 
     8 calcGasto[4] B              0            -0             = 
     9 calcGasto[5] B              0            -0             = 
    10 ano[4,3,2,1] B              0            -0             = 
    11 ano[5,4,3,2] B              0            -0             = 
    12 comeco       B              0          5000             = 
    13 calcFinal[1] B              0            -0             = 
    14 calcFinal[2] B              0            -0             = 
    15 calcFinal[3] B              0            -0             = 
    16 calcFinal[4] B              0            -0             = 
    17 calcFinal[5] B              0            -0             = 
    18 calcInicial[2,1]
                    B              0            -0             = 
    19 calcInicial[3,2]
                    B              0            -0             = 
    20 calcInicial[4,3]
                    B              0            -0             = 
    21 calcInicial[5,4]
                    B              0            -0             = 
    22 s4[1]        B              0          5000             = 
    23 s4[2]        B              0          5000             = 
    24 s4[3]        B              0          5000             = 
    25 s4[4]        B              0          5000             = 
    26 s4[5]        B              0          5000             = 
    27 s5[1]        B              0            -0             = 
    28 s5[2]        B              0            -0             = 
    29 s5[3]        B              0            -0             = 
    30 s5[4]        B              0            -0             = 
    31 s5[5]        B              0            -0             = 
    32 investimento B              0                             
    33 logica[1]    B              0                          -0 
    34 logica[2]    B              0                          -0 
    35 logica[3]    B              0                          -0 
    36 logica[4]    B              0                          -0 
    37 logica[5]    B              0                          -0 

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 x[1]         NL             0             0                       < eps
     2 x[2]         NL             0             0                       < eps
     3 x[3]         NL             0             0                       < eps
     4 x[4]         NL             0             0                       < eps
     5 x[5]         NL             0             0                       < eps
     6 y[1]         NL             0             0                       < eps
     7 y[2]         NL             0             0                       < eps
     8 y[3]         NL             0             0                       < eps
     9 y[4]         NL             0             0                       < eps
    10 y[5]         NL             0             0                       < eps
    11 z[1]         NL             0             0                       < eps
    12 z[2]         NL             0             0                       < eps
    13 z[3]         NL             0             0                       < eps
    14 z[4]         NL             0             0                       < eps
    15 z[5]         NL             0             0                       < eps
    16 sx           NF             0                                     < eps
    17 sy           NF             0                                     < eps
    18 sz           NF             0                                     < eps
    19 gasto[1]     NF             0                                     < eps
    20 gasto[2]     NF             0                                     < eps
    21 gasto[3]     NF             0                                     < eps
    22 gasto[4]     NF             0                                     < eps
    23 gasto[5]     NF             0                                     < eps
    24 rend[4]      NF             0                                     < eps
    25 rend[5]      NF             0                                     < eps
    26 rend[2]      NF             0                                     < eps
    27 rend[3]      NF             0                                     < eps
    28 inicial[1]   NF             0                                     < eps
    29 inicial[2]   NF             0                                     < eps
    30 inicial[3]   NF             0                                     < eps
    31 inicial[4]   NF             0                                     < eps
    32 inicial[5]   NF             0                                     < eps
    33 final[1]     NF             0                                     < eps
    34 final[2]     NF             0                                     < eps
    35 final[3]     NF             0                                     < eps
    36 final[4]     NF             0                                     < eps
    37 final[5]     NF             0                                     < eps
    38 a[1]         NF             0                                     < eps
    39 a[2]         NF             0                                     < eps
    40 a[3]         NF             0                                     < eps
    41 a[4]         NF             0                                     < eps
    42 a[5]         NF             0                                     < eps
    43 itrs[1]      NF             0                                     < eps
    44 itrs[2]      NF             0                                     < eps
    45 itrs[3]      NF             0                                     < eps
    46 itrs[4]      NF             0                                     < eps
    47 itrs[5]      NF             0                                     < eps

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

KKT.PB: max.abs.err = 5.00e+03 on row 12
        max.rel.err = 1.00e+00 on row 12
        PRIMAL SOLUTION IS INFEASIBLE

KKT.DE: max.abs.err = 1.15e+00 on column 18
        max.rel.err = 5.35e-01 on column 18
        DUAL SOLUTION IS WRONG

KKT.DB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
