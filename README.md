# Conversor de Bases Numéricas
- Este é um programa desenvolvido em C como parte das atividades da disciplina de Redes de Computadores do 2º semestre de Engenharia de Software no Centro Universitário Católica de Santa Catarina.
- O objetivo principal é realizar a conversão de números entre os sistemas Binário, Decimal e Hexadecimal de forma intuitiva e segura.

## 🚀 Funcionalidades
- Conversão Multidirecional: Suporta a conversão entre as bases 2 (Binário), 10 (Decimal) e 16 (Hexadecimal).
- Validação de Entrada: O sistema verifica se o número digitado é compatível com a base de origem selecionada, evitando erros de processamento.
- Fluxo Contínuo: Implementação de um loop de repetição que permite realizar diversas conversões em uma única execução do programa.
- Segurança de Memória: Tratamento de buffer de entrada para garantir a estabilidade durante a leitura de dados.

## 🧠 Lógica de Conversão
- O programa utiliza a estratégia de Ponte Decimal.
- Independentemente da base de origem, o valor é primeiro convertido para a base decimal (Base 10) e, a partir dela, transformado para a base de destino desejada.
  - De Base X para Decimal: Utiliza a soma dos produtos dos dígitos pela base elevada à sua respectiva posição.
  - De Decimal para Base Y: Utiliza o método de divisões sucessivas, armazenando os restos para compor o resultado final.

## 🛠️ Como Executar
- Para compilar e rodar o projeto, você precisará de um compilador C
- Clone o repositório
- Navegue até a pasta do projeto e execute o arquivo principal

## 📝 Tecnologias Utilizadas
- Linguagem: C
- Bibliotecas Standard: stdio.h, stdlib.h, string.h, math.h

## 
<img width="381" height="138" alt="conversor01-origem" src="https://github.com/user-attachments/assets/ce21b3d7-c8f7-4376-9e2e-2901cca300df" /> <br>
<img width="393" height="141" alt="conversor02-destino" src="https://github.com/user-attachments/assets/4f2ac809-61d2-4f3a-b3bc-2b114cd7befb" /> <br>
<img width="445" height="151" alt="conversor03-resultado" src="https://github.com/user-attachments/assets/ca555b75-c8ff-45a9-806c-63252824f11b" />


