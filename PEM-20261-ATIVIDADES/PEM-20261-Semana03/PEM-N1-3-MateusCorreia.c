#include <stdio.h>

int main()
{
    int idProduto[10] = {0};
    int opcao, id, i, encontrado = 0;

    do
    {
        printf("\n==== Cadastro de produto ====\n");
        printf("1 - Inclusao\n");
        printf("2 - Consulta\n");
        printf("3 - Alteracao\n");
        printf("4 - Exclusao\n");
        printf("5 - Listar todos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite o ID do produto: ");
            scanf("%d", &id);

            for (i = 0; i < 10; i++)
            {
                if (idProduto[i] == 0)
                {
                    idProduto[i] = id;
                    break;
                }
            }
            break;

        case 2:
            printf("\nDigite o ID para busca: ");
            scanf("%d", &id);

            for (i = 0; i <= 9; i++)
            {
                if (idProduto[i] == id)
                {
                    printf("Produto encontrado na posicao %d\n", i+1);
                    encontrado = 1;
                }
            }

            if(encontrado == 0){
                printf("Produto nao encontrado!");
            }
            break;

        case 3:
            printf("\nDigite o ID para alteracao: ");
            scanf("%d", &id);

            for (i = 0; i < 10; i++)
            {
                if (idProduto[i] == id)
                {
                    printf("Digite o novo ID: ");
                    scanf("%d", &id);
                    idProduto[i] = id;
                    encontrado = 1;
                    break;
                }
            }
            if(encontrado == 0){
                printf("Produto nao encontrado!");
            }
            
            break;

        case 4:
            printf("\nDigite o ID para exclusao: ");
            scanf("%d", &id);

            for (i = 0; i < 10; i++)
            {
                if(idProduto[i] == id){
                    idProduto[i] = 0;
                    printf("Produto excluido com sucesso");
                    encontrado = 1;
                    break;
                }
            }
            if(encontrado == 0){
                printf("Produto nao encontrado!");
            }
            
            break;

        case 5:
            for (i = 0; i < 10; i++)
            {
                if(idProduto[i] != 0){
                    printf("Produto na posicao %d: %d\n", i+1, idProduto[i]);
                }
            }
            
            break;

        case 0:
            printf("\nEncerrando programa...");
            break;

        default:
            printf("Opcao invalida!");
            break;
        }
    } while (opcao != 0);
}