pra executar:

1- gcc selectionsort_aut.c -o selectionsort_aut OU gcc selectionsort.c -o selectionsort

2- ./selectionsort_aut OU ./selectionsort

explicação:

o selectionsort_aut.c faz tudo automaticamente, executando 1000 vezes cada uma das quantidade de elementos(500, 1000, 1500...5000) e salvando no arquivo final o tempo pra cada quantidade de elementos certinho.

o selectionsort.c pede a quantidade de elementos e a quantidade de vezes que quer executar(ex: 500 elementos, 1000 vezes) e salva apenas os tempos dessa execução no arquivo final.

obs:

- arquivo arq_teste.txt(com os 5000 elementos pra ordenação) precisa estar na mesma pasta que o arquivo C do selection.
