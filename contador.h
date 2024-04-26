#include "tabela.h"

class ContadorBinario : private Tabela<int> {
    public:
        ContadorBinario():  Tabela<int>()
        {
            inserir(1);
        }
        void incrementar(){
            for (int i = getPosicaoUltimoElemento(); i >= 0; --i){
                if (getElemento(i) == 0){
                    inserir(1, i);
                    for (int j = i + 1; j <= getPosicaoUltimoElemento(); ++j){
                        inserir(0, j);
                    }
                    return;
                }
            }
            inserir(0);
            for (int i = 1; i <= getPosicaoUltimoElemento(); ++i){
                inserir(0, i);
            }
        }
        void decrementar(){
            for (int i = getPosicaoUltimoElemento(); i >= 0; --i){
                if (getElemento(i) == 1){
                    inserir(0, i);
                    for (int j = i + 1; j <= getPosicaoUltimoElemento(); ++j){
                        inserir(1, j);
                    }
                    if (i == 0){
                        remover(0);
                    }
                    return;
                }
            }
        }
        std::string getContagem() const{
            std::string cont = "";
            for (int i = 0; i <= getPosicaoUltimoElemento(); ++i){
                cont += std::to_string(getElemento(i));
            }
            if (cont == ""){
                cont = "0";
            }
            return cont;
        }

        int getCusto() const{
            return custo;
        }
};