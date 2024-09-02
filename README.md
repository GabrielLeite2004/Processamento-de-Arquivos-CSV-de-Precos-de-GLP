# Processamento-de-Arquivos-CSV-de-Precos-de-GLP

## Descrição
Este projeto em C realiza o processamento de arquivos CSV contendo informações sobre preços de GLP (Gás Liquefeito de Petróleo) coletados em diferentes regiões do Brasil. O código lê os dados de um arquivo CSV, filtra as informações com base na região e salva os resultados filtrados em um arquivo de texto. O projeto faz uso de uma estrutura (struct) para armazenar os dados e de uma lista para gerenciar os registros.

## Funcionalidades
- Leitura de arquivos CSV contendo informações sobre revendas de GLP.
- Filtragem de dados com base na sigla da região (NE, N, S, SE, CO).
- Salvamento dos dados filtrados em um arquivo de saída.
- Estruturação dos dados em uma lista para manipulação e consulta.

## Como Usar
1. Certifique-se de que o arquivo `glp-2004-01.csv` esteja no mesmo diretório do código-fonte.
2. Compile o código utilizando um compilador C. Exemplo:
   ```bash
   gcc -o processa_glp processa_glp.c tad_lst2.c
   ```
3. Execute o programa:
   ```bash
   ./processa_glp
   ```
4. O resultado será salvo em um arquivo chamado `glp-2004-01.txt`, contendo as informações filtradas e formatadas.

## Estrutura de Dados
O projeto utiliza uma estrutura `Dados` para armazenar cada registro do arquivo CSV. A estrutura é composta pelos seguintes campos:
- `regiao_sigla`: Sigla da região (ex: NE, SE).
- `estado_sigla`: Sigla do estado (ex: SP, RJ).
- `municipio`: Nome do município.
- `revenda`: Nome da revenda.
- `cnpj_revenda`: CNPJ da revenda.
- `data_coleta`: Data da coleta do preço.
- `valor_venda`: Valor de venda do GLP.

## Dependências
- Biblioteca padrão de C (`stdio.h`, `stdlib.h`, `string.h`).
- Arquivo de cabeçalho `tad_lst2.h` para manipulação de listas.

## Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests.

## Licença
Este projeto está licenciado sob a [MIT License](LICENSE).
