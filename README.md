# Alunos
- Gabriel Lisboa Conegero: GRR20221255
- Daniel Celestino de Lins Neto: GRR20220064

# Relatório
A escolha para "quebrar" o RSA foi fatorar o valor n da chave pública e recalcular
a chave privada como é feito na hora de criptografar.

## Algoritmo de fatorar n
O algoritmo escolhido foi o de tentativa e erro, testando todos os números
até `sqrt(n)`, atualizando n após conseguir um valor.

## Algoritmo de inverso multiplicativo de e
O algoritmo escolhido para realizar o inverso multiplicativo de `d*e = 1 (mod phi(n))`
foi o **Extended Euclidean Algorithm**.

## Observações
A implementação funciona para toda chave pública que respeite
- `e` é positivo e cabe em **64** bits;
- `n` é positivo e cabe em **64** bits;
