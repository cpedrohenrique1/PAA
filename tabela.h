#include <iostream>

template <typename T>
class Tabela{
    private: 
        T *vetor;
        int tamanho_vetor;
        int posicao_ultima;
    protected:
        int custo;
    public:
        Tabela():   vetor(0), 
                    tamanho_vetor(1),
                    posicao_ultima(-1),
                    custo(0)
        {
            try{
                vetor = new T[tamanho_vetor];
            }catch(std::bad_alloc& e){
                throw std::string("Nao foi possivel alocar memoria");
            }
        }
        Tabela(int tamanho_vetor):  vetor(0),
                                    tamanho_vetor(0),
                                    posicao_ultima(-1),
                                    custo(0)
        {
            try{
                if (tamanho_vetor <= 0){
                    throw std::string("tamanho invalido");
                }
                this->tamanho_vetor = tamanho_vetor;
                vetor = new T[tamanho_vetor];
            }catch(std::bad_alloc&e){
                throw std::string("erro ao alocar memoria");
            }
        }
        ~Tabela(){
            if (vetor){
                delete[] vetor;
            }
        }
        T getElemento(int posicao) const{
            if (!vetor){
                throw std::string("vetor vazio");
            }
            if (posicao < 0){
                throw std::string("Posicao invalida, nao pode ser < 0");
            }
            if (posicao >= tamanho_vetor){
                throw std::string("Posicao invalida, nao possui elemento nessa posicao");
            }
            return vetor[posicao];
        }
        int getTamanhoVetor() const{
            return tamanho_vetor;
        }
        int getPosicaoUltimoElemento() const{
            return posicao_ultima;
        }
        void alocarEspaco(){
            if (!vetor){
                throw std::string("vetor vazio");
            }
            try{
                this->tamanho_vetor = tamanho_vetor * 2;
                T *vetor_novo = new T[tamanho_vetor];
                for (int i = 0; i <= posicao_ultima; ++i){
                    vetor_novo[i] = vetor[i];
                    custo++;
                }
                delete[] vetor;
                vetor = vetor_novo;
                custo += 5;
            }catch(std::bad_alloc&e){
                throw std::string("Erro ao alocar vetor");
            }
        }
        void inserir(T elemento){
            if (posicao_ultima == tamanho_vetor - 1){
                alocarEspaco();
            }
            custo += 2;
            vetor[++posicao_ultima] = elemento;
        }
        void inserir(T elemento, int posicao){
            if (posicao < 0){
                throw std::string("posicao invalida");
            }
            while (posicao > tamanho_vetor - 1){
                alocarEspaco();
            }
            vetor[posicao] = elemento;
            if (posicao > posicao_ultima){
                this->posicao_ultima = posicao;
            }
            custo += 3;
        }
        void remover(){
            if (!vetor || posicao_ultima == -1){
                throw std::string("vetor vazio");
            }
            --posicao_ultima;
        }
        void remover(int posicao){
            if (posicao < 0){
                throw std::string("posicao invalida");
            }
            if (posicao > posicao_ultima){
                throw std::string("posicao invalida, nao possui elemento nessa posicao");
            }
            for (int i = posicao; i < posicao_ultima; ++i){
                vetor[i] = vetor[i + 1];
                custo++;
            }
            custo++;
            --posicao_ultima;
        }
        int getCusto() const{
            return custo;
        }
};