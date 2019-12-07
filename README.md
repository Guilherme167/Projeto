# Manual do Programa

Projeto desenvolvido atraves do programa Qt Creator pelo aluno Guilherme Costa, curso Engenharia Elétrica-IFPB. O programa ao qual este manual se refere é, um aplicativo de simulação de um circuito RLC alimentado por um fonte de tensão senoidal, sendo um tipo bem comum de carga elétrica, para assim analizar o comportamento do mesmo em certas condições.

# Objetivo da aplicação

Muitas vezes, para fim de pesquisas cientificas ou práticos no mercado de trabalho, se torna necessário investir em programas que atendam as necessidades dos profisionais de cada área. Nesse viés, este progrograma busca proporcionar, de forma rápida e prática, resultados para análise de um técnico de um circuito RLC.
Os circuitos RLC são compostos por elementos resistivos, indutivos e capacitivos. Caracterizando a maior parte das cargas elétricas que podemos encontrar no dia a dia. Dessa forma, é extremamente viável optar por programas deste gênero para facilitar o trabalho e aumentar a produtividade.

# Utilizando o simulador:

O programa possui uma interface simples que facilita a sua utilização, aqui temos a sua tela principal:

![1-interface](https://github.com/Guilherme167/Projeto/blob/master/imagens/1-interface.png)

Nas caixas de texto é possível inserir os valores de cada componente do circuito que se deseja simular, como o valor eficaz da tensão senoidal da fonte por exemplo. Tais valores devem ser inseridos apenas na forma de números positivos separados por ponto (no lugar de vírgulas) se necessário:

![2-valores](https://github.com/Guilherme167/Projeto/blob/master/imagens/2-valores.png)

Utilizando a caixa com uma seta para baixo, é possivel selecionar o passo de calculo e o tempo de simulação entre os valores que o programa fornece. Quanto menor o passo de calculo, mais precisos serão os resultados da simulação. Um tempo de simulação maior pode ser utilizado para observar a forma de onda quando o circuito demora mais tempo para entrar em regime permanente.

![3-seleção](https://github.com/Guilherme167/Projeto/blob/master/imagens/3-sele%C3%A7%C3%A3o.png)

# Simulação

Basta pressionar, com o botão esquerdo do mouse, o botão escrito "Simular" pra assim iniciar os calculos do programa. Caso tudo ocorra bem, a seguinte mensagem irá aparecer para o usuário:

![4-simulando](https://github.com/Guilherme167/Projeto/blob/master/imagens/4-simulando.png)

Caso falte algum campo a ser preenchido, a simulação não ocorrerá, aparecendo a mensagem:

![5-erro1](https://github.com/Guilherme167/Projeto/blob/master/imagens/5-erro1.png)

O mesmo ocorrerá caso o usuário insira valores que não sejam válidos, como caracteres especiais, letras, vírgulas, ou valores nulos (zero), exibindo a mensagem de erro para serem inseridos apenas valores positivos.

![6-erro2](https://github.com/Guilherme167/Projeto/blob/master/imagens/6-erro2.png)

# Gráficos

Quando a simulação for concluida, após alguns instantes, será possível acessá-los atraves da segunda aba superior onde está escrito "Simulação", sendo possível observar os gráficos pra cada componente do circuito no tempo pela amplitude dos valores. Os gráficos em azul representam a tensão e, os em vermelho, a corrente elétrica.

![7-plot](https://github.com/Guilherme167/Projeto/blob/master/imagens/7-plot.png)

Os gráficos são interativos, sendo possível interagir com os mesmos. Ao clicar (com o botão esquerdo do mouse) e arrastar é possível deslocar o gráfico e, utilizando o scroll do mouse (botão do meio do mouse) é possível aproximar ou distanciar o gráfico, de acordo com o gosto do usuário.

![8-zoom](https://github.com/Guilherme167/Projeto/blob/master/imagens/8-zoom.png)

Clicando com o botão esquerdo do mouse também é possível selecionar os gráficos individualmente, caso o usuário deseje destacá-lo em certas simulações:

![9-seleção](https://github.com/Guilherme167/Projeto/blob/master/imagens/9-sele%C3%A7%C3%A3o.png)

# Tabela

Selecionando a aba "resultados" é possível analisar, por meio de uma tabela, os valores de tensão e corrente de cada componente do circuito na forma de vetores. Nesta seção, pode-se organizar os vetores da tabela de duas formas: em ordem crescente do módulo dos vetores, ou, em ordem crescente do ângulo de fase dos mesmos. Além disso, também temos a opção de apagar os vetores da tabela, a fim de limpa-la;

![16-tabela](https://github.com/Guilherme167/Projeto/blob/master/imagens/16-tabela.png)

# Opções de menu

Acessando a barra superior do programa é possivel acessar algumas opções a cerca do mesmo. Entre elas, temos a opção abrir, que abre um arquivo do formato ".csv" do computador do usuário, referente a uma simulção salva, para exibir informações de uma simulação especifica que se deseja.

![10-abrir](https://github.com/Guilherme167/Projeto/blob/master/imagens/10-abrir.png)

Basta escolher um arquivo ".csv", que não esteja vazio, para ser aberto:

![15-abrirArq](https://github.com/Guilherme167/Projeto/blob/master/imagens/15-abrirArq.png)

A opção salvar cria uma arquivo ".csv" para salvar os valores de cada vetor do circuito:

![11-salvar](https://github.com/Guilherme167/Projeto/blob/master/imagens/11-salvar.png)

Que abre a seguinte caixa de texto para o usuário escolher o local e o nome do arquivo que deseja salvar:

![14-salvarArq](https://github.com/Guilherme167/Projeto/blob/master/imagens/14-salvarArq.png)

A opção sair, ao ser presionad, fecha a janela do programa, encerrando o mesmo:

![12-sair](https://github.com/Guilherme167/Projeto/blob/master/imagens/12-sair.png)

A opção consultar manual, na aba Ajuda ao lado do Menu, abre o navegador e o direciona para o link deste manual, esta opção pode ser utilizada caso o usuário tenha alguma dúvida de como utilizar o programa:

![13-ajuda](https://github.com/Guilherme167/Projeto/blob/master/imagens/13-ajuda.png)

# Uma breve teoria

Este projeto foi realizado atraves do estudo de circuitos elétricos. A priori, para montar o modelo matemático do circuito com derivadas e integrais foi necessário utilizar a lei de kirchhoff para as tensões e correntes e, com manipulações algébricas, para colocar certos termos em evidência a fim de obter resultados com os parâmetros fornecidos pelo usuário do programa.
Entre esses resultados, temos valores de tensão e corrente na forma de vetores, com seus respectivos ângulos de fase. Valores estes que foram alcançados por meio de uma matriz com números complexos.

![17-calculo]()

# Arquivos externos

Para plotar de maneira mais fácil os gráficos aqui apresentados foi utilizado um pacote que não pertence a biblioteca padrão do Qt Creator. Este pacote é chamado QCustomPlot, que está disponível em "https://www.qcustomplot.com/" com uma versão gratuita. Com o mesmo, é possível criar uma gama gigantesca de gráficos dos mais vaiados tipos. Dessa maneira, neste projeto foi utilizado uma pequena parcela do verdadeiro potencial deste pacote.
