param initial;

param oneI;
param twoI;
param threeI;

set one := {1..5}; /* conjunto de indices de fazendas */

var x { i in one } >= 0;
var y { i in one } >= 0;
var z { i in one } >= 0;
s.t. inicioTardio: z [1] = 0;

var sx ;
s.t. s1 : sx = sum { i in one } x[i];
var sy ;
s.t. s2 : sy = sum { i in one } y[i];
var sz ;
s.t. s3 : sz = sum { i in one } z[i];

var gasto { i in one };
s.t. calcGasto { i in one } : gasto [i] = x[i] + y[i] + z[i];

var rend { i in one } ;
s.t. ano { i in one, j in one, k in one, l in one : j > 0 && j = i-1 && k = i-2 && k > 0 && l > 0 && l = i-3 } : rend [i] = x[j]*oneI + y[k]*twoI + z[l]*threeI;

var inicial { i in one };
var final { i in one };

s.t. comeco : inicial[1] = initial;
s.t. calcFinal { i in one } : final[i] = inicial[i] - gasto[i];
s.t. calcInicial { i in 2..5, j in 1..5 : j = i - 1 } : inicial[i] = final[j] + rend[i];

/*
                                */
var a { i in one };
s.t. s4 { i in one } : a[i]  = initial - sum { j in 1..i } x[j] - sum { j in 1..i-1 } y[j]
                                - sum { k in 2..3 } z[k] ;

var itrs { i in one };
s.t. s5 { i in one } : itrs [i] = oneI * sum { j in 2..i } x[j-1] + twoI * sum { k in 3..i } y[k-2] + threeI * sum { l in 5..i } z[l-3] ;

maximize investimento:
    oneI * sx + twoI * sy + threeI * sz;

s.t. logica { i in one } : gasto[i] <= inicial[i] ;

/*
s.t. ano1: x[1] + y[1] <= initial;
s.t. ano2: x[2] + y[2] + z[2] <= initial - ( x[1] + y[1] ) + oneI * x[1]; 
s.t. ano3: x[3] + y[3] + z[3] <= initial - ( x[1] + y[1] ) - ( x[2] + y[2] + z[2] ) + oneI * (x[1] + x[2] ) + twoI * y[1] ; 
s.t. ano4: x[4] + y[4] <= initial - ( x[1] + y[1] ) - ( x[2] + y[2] + z[2] ) - ( x[3] + y[3] + z[3] ) + oneI * (x[1] + x[2] + x[3] ) + twoI * ( y[1] + y[2] ); 
s.t. ano5: x[5] <= initial - ( x[1] + y[1] ) - ( x[2] + y[2] + z[2] ) - ( x[3] + y[3] + z[3] ) + oneI * (x[1] + x[2] + x[3] + x[4] ) + twoI * ( y[1] + y[2] + y[3] ) + threeI * z[2];  

s.t. y1 : x[1] + y[1] <= a [1];
s.t. y2 : x[2] + y[2] + z[2] <= a [2] + itrs [2];
s.t. y3 : x[3] + y[3] + z[3] <= a [3];
s.t. y4 : x[4] + y[4] <= a [4];
s.t. y5 : x[5] <= a [5];
*/

solve;

printf: "Invest: %d\n", oneI * sx + twoI * sy + threeI * sz;

printf { i in one }: "oneYear[%d] = %d\n", i, x[i];
printf { i in one }: "twoYears[%d] = %d\n", i, y[i];
printf { i in one }: "threeYears[%d] = %d\n", i, z[i];
printf { i in one }: "spent[%d] = %d\n", i, gasto[i];
printf { i in one }: "interest[%d] = %d\n", i, rend[i];
printf { i in one }: "inicial[%d] = %d\n", i, inicial[i];
printf { i in one }: "final[%d] = %d\n", i, final[i];

end;
