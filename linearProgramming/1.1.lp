Problem:    1
Rows:       24
Columns:    24
Non-zeros:  131
Status:     OPTIMAL
Objective:  investimento = 5650 (MAXimum)

   No.   Row name   St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 s1           NS             0            -0             =          1.04 
     2 s2           NS             0            -0             =          1.09 
     3 s3           NS             0            -0             =          1.15 
     4 s4[1]        NS          5000          5000             =         < eps
     5 s4[2]        NS          5000          5000             =          0.02 
     6 s4[3]        NS          5000          5000             =          0.02 
     7 s4[4]        NS          5000          5000             =      0.533303 
     8 s4[5]        NS          5000          5000             =          0.52 
     9 s5[1]        NS             0            -0             =         < eps
    10 s5[2]        NS             0            -0             =          0.02 
    11 s5[3]        NS             0            -0             =         < eps
    12 s5[4]        NS             0            -0             =         < eps
    13 s5[5]        NS             0            -0             =         < eps
    14 investimento B           5650                             
    15 ano1         B              0                        5000 
    16 ano2         B        1666.67                        5000 
    17 ano3         B        3333.33                        5000 
    18 ano4         NU          5000                        5000     0.0366972 
    19 ano5         B        1416.67                        5000 
    20 y1           B       -1666.67                          -0 
    21 y2           NU             0                          -0          0.02 
    22 y3           NU             0                          -0          0.02 
    23 y4           NU             0                          -0      0.533303 
    24 y5           NU             0                          -0          0.52 

   No. Column name  St   Activity     Lower bound   Upper bound    Marginal
------ ------------ -- ------------- ------------- ------------- -------------
     1 x[1]         NL             0             0                  -0.0310349 
     2 x[2]         NL             0             0                  -0.0718349 
     3 x[3]         NL             0             0                  -0.0518349 
     4 x[4]         NL             0             0                   -0.583303 
     5 x[5]         B              0             0               
     6 y[1]         B              0             0               
     7 y[2]         NL             0             0                       < eps
     8 y[3]         NL             0             0                       -0.02 
     9 y[4]         B        1666.67             0               
    10 z[2]         B        1666.67             0               
    11 z[3]         B        1666.67             0               
    12 sx           B              0                             
    13 sy           B        1666.67                             
    14 sz           B        3333.33                             
    15 a[1]         B        1666.67                             
    16 a[2]         B        1666.67                             
    17 a[3]         B        1666.67                             
    18 a[4]         B        1666.67                             
    19 a[5]         B              0                             
    20 itrs[1]      B              0                             
    21 itrs[2]      B              0                             
    22 itrs[3]      B              0                             
    23 itrs[4]      B              0                             
    24 itrs[5]      B        1916.67                             

Karush-Kuhn-Tucker optimality conditions:

KKT.PE: max.abs.err = 9.09e-13 on row 4
        max.rel.err = 9.09e-17 on row 4
        High quality

KKT.PB: max.abs.err = 6.00e-14 on column 5
        max.rel.err = 6.00e-14 on column 5
        High quality

KKT.DE: max.abs.err = 2.22e-16 on column 1
        max.rel.err = 6.97e-17 on column 1
        High quality

KKT.DB: max.abs.err = 0.00e+00 on row 0
        max.rel.err = 0.00e+00 on row 0
        High quality

End of output
