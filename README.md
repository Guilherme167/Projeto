# Manual do Programa

Projeto desenvolvido atraves do programa Qt Creator pelo aluno Guilherme Costa, curso Engenharia Elétrica-IFPB. O programa ao qual este manual se refere é, um aplicativo de simulação de um circuito RLC, sendo um tipo bem comum de carga elétrica, para assim analizar o comportamento do mesmo em certas condições.

# Objetivo da aplicação

Muitas vezes, para fim de pesquisas cientificas ou práticos no mercado de trabalho, se torna necessário investir em programas que atendam as necessidades dos profisionais de cada área. Nesse viés, este progrograma busca proporcionar, de forma rápida e prática, resultados para análise de um técnico de um circuito RLC.
Os circuitos RLC são compostos por elementos resistivos, indutivos e capacitivos. Caracterizando a maior prte das cargas elétricas que podemos encontrar no dia a dia. Dessa forma, é extremamente viávem optar por programas deste gênero para facilitar o trabalho e aumentar a produtividade.

# Utilizando o simulador:

O programa possui uma interface simples que facilita a sua utilização, aqui temos a sua tela principal:
![1-interface]()

Nas caixas de texto é possível inserir os valores de cada componente do circuito que se deseja simular, devem ser inseridos apenas números positivos seprados por ponto (no lugar de vírgulas) se necessário:
![2-valores]()

Utilizando a caixa com uma seta para baixo, é possivel selecionar o passo de calculo e o tempo de simulação entre os valores que o programa fornece. Quanto menor o passo de calculo, mais precisos serão os resultados da simulação. Um tempo de simulação maior pode ser utilizado para observar a forma de onda quando o circuito demora mais tempo para entrar em regime permanente.
![3-seleção]()

# Simulação

Basta pressionar, com o botão esquerdo do mouse, o botão escrito "Simular" pra assim iniciar os calculos do programa. Caso tudo ocorra bem, a seguinte mensagem irá aparecer para o usuário:
![4-simulando]()

Caso falte algum campo a ser preenchido, a simulação não ocorrerá, aparecendo a mensagem:
![5-erro1]()

O mesmo ocorrerá caso o usuário insira valores que não sejam válidos, como caracteres especiais, letras, vírgulas, ou valores nulos (zero), exibindo a mensagem de erro para serem inseridos apenas valores positivos.
![6-erro2]()

# Gráficos

Quando a simulção for concluida, após alguns instantes, será possível acessá-los atraves da segunda aba superior onde está escrito "Simulção", sendo possível observar os gráficos pra cada componente do circuito no tempo pela amplitude dos valores. Os gráficos em azul representam a tensão e, os em vermelho, a corrente elétrica.
![7-plot]()

Os gráficos são interativos, sendo possível interagir com os mesmos. Ao clicar (com o botão esquerdo do mouse) e arrastar é possível deslocar o gráfico e, utilizando o scroll do mouse (botão do meio do mouse) é possível aproximar ou distanciar o gráfico, ajuntando de acordo com o gosto do usuário.
![8-zoom]()

Clicando com o botão esquerdo do mouse também é possível selecionar os gráficos individualmente, caso o usuário deseje destacá-lo em certas simulações:
![9-seleção]()



# Opções de menu

Acessando a barra superior do programa é possivel acessar algumas opções a cerca do mesmo. Entre elas, temos a opção abrir, que abre um arquivo do formato ".csv" do computador do usuário, referente a uma simulção salva, para exibir informações de uma simulação especifica que se deseja.
![10-abrir]()

A opção salvar cri uma arquivo ".csv" para salvar os valores dos vetores
![11-salvar]()
![12-sair]()
![13-ajuda]()



# Teoria


# Arquivos externos

Para plotar de maneira mais fácil os gráficos aqui apresentados foi utilizado um pacote que não pertence a biblioteca padrão do Qt Creator. Este pacote é chamado QCustomPlot, que está disponível em "https://www.qcustomplot.com/" com uma versão gratuita. Com o mesmo, é possível criar uma gama gigantesca de gráficos dos mais vaiados tipos. Dessa maneira, neste projeto foi utilizado uma pequena parcela do verdadeiro potencial deste pacote.


