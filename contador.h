#include "tabela.h"

class ContadorBinario : protected Tabela<int> {
    public:
        ContadorBinario():  Tabela<int>()
        {}
        void incrementar(){
            
        }
        void decrementar(){

        }
        std::string getContagem() const{
            std::string cont = "";
            for (int i = 0; i < getTamanhoVetor(); ++i){
                cont += getElemento(i);
            }
            return cont;
        }
};