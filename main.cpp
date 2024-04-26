#include "contador.h"

int main(){
    try{
        ContadorBinario c1;
        int custo = 0;
        int contagem = 10;
        for (int i = 0; i < contagem; ++i){
            std::cout << c1.getContagem() << '\n';
            c1.incrementar();
            std::cout << "Custo " << i << ": " << c1.getCusto()<< '\n';
        }
        std::cout << "Custo: " << c1.getCusto() << '\n';
        std::cout << "Custo amortizado: " << c1.getCusto() / contagem << '\n';
    }catch(std::string& e){
        std::cout << "Erro: " << e << '\n';
    }
    return 0;
}