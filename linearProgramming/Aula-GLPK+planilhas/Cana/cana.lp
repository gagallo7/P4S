\* Problem: cana *\

Minimize
 custo: + 21 x(1,1) + 50 x(1,2) + 40 x(1,3) + 35 x(2,1) + 30 x(2,2)
 + 22 x(2,3) + 55 x(3,1) + 20 x(3,2) + 25 x(3,3)

Subject To
 escoamento(1): + x(1,1) + x(1,2) + x(1,3) <= 275
 escoamento(2): + x(2,1) + x(2,2) + x(2,3) <= 400
 escoamento(3): + x(3,1) + x(3,2) + x(3,3) <= 300
 escoamentoXprocessamento: + x(1,1) + x(1,2) + x(1,3) + x(2,1) + x(2,2)
 + x(2,3) + x(3,1) + x(3,2) + x(3,3) = 975
 processa(1): + x(1,1) + x(2,1) + x(3,1) <= 200
 processa(2): + x(1,2) + x(2,2) + x(3,2) <= 600
 processa(3): + x(1,3) + x(2,3) + x(3,3) <= 225

End
