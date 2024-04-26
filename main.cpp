#include "contador.h"

int main(){
    try{
        ContadorBinario c1;
        int custo = 0;
        int contagem = 10;
        for (int i = 0; i < contagem; ++i){
            std::cout << c1.getContagem() << '\n';
            c1.incrementar();
        }
        std::cout << "Custo amortizado: " << '\n';
    }catch(std::string& e){
        std::cout << "Erro: " << e << '\n';
    }
    return 0;
}