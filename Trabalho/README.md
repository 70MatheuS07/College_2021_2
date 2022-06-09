Alunos: Matheus de Oliveira e Yan Maia

Como é um trabalho extenso, optamos por começar discutindo e dividindo-o em partes, são elas:

1º - Pré jogo.
2º - Jogo.
3º - Pós jogo (resultado).

O pré jogo foi o momento em que pensamos nas structs e aquelas funções que seriam
indispensáveis dentro da main, para executar o padronizar e coletar as informações
que seriam armazenadas.

No jogo, inicialmente, declaramos diversas variáveis dentro da função PlayGame.
Na metade do código, notamos que era viável a criação de uma struct tPlaying playing
para organizar a função.

O pós jogo escrevemos, primeiramente, em um papel fazendo a cobertura de todas as possibilidades
existentes de resultados para não haver nenhum problema com looping infinito ou resposta errada,
logo depois passado para a função ResultadoJogo.

Após fazer essas 3 partes o código estava extenso com cerca 2700 linhas. Começamos a sintetizá-lo
usando looping's ao invés de diversos if's; E também, ao longo desses looping's foram feitos pontos
de break pensando em evitar a leitura de código desnescessário (a inicialização das variáveis também 
ajudou muito nesse quesito).