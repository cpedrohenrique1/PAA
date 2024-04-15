#include <iostream>

template <typename T>
class Tabela{
    private: 
        T *vetor;
        int tamanho_vetor;
        int posicao_ultima;
    public:
        Tabela():   vetor(0), 
                    tamanho_vetor(0),
                    posicao_ultima(-1)
        {}
        Tabela(int tamanho_vetor):  vetor(0),
                                    tamanho_vetor(0),
                                    posicao_ultima(-1)
        {
            try{
                if (tamanho_vetor < 0){
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
                tamanho_vetor = 0;
                posicao_ultima = -1;
                delete[] vetor;
                vetor = 0;
            }
        }
        T getVetor(int posicao) const{
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
        void alocarVetor(){
            try{
                T *vetor_novo = new T[tamanho_vetor * 2];
                for (int i = 0; i <= posicao_ultima; ++i){
                    vetor_novo[i] = vetor[i];
                }
                delete[] vetor;
                vetor = 0;
                vetor = vetor_novo;
                tamanho_vetor = tamanho_vetor * 2;
            }catch(std::bad_alloc&e){
                throw std::string("Erro ao alocar vetor");
            }
        }
        void inserir(T elemento, int posicao){
            if (posicao < 0 || posicao >= tamanho_vetor){
                throw std::string("posicao invalida");
            }
            vetor[posicao] = elemento;
            posicao_ultima = posicao;
        }
        void inserir(T elemento){
            if (!vetor){
                try{
                    vetor = new T[tamanho_vetor];
                    this->tamanho_vetor = 1;
                }catch(std::bad_alloc&e){
                    throw std::string("Erro ao alocar memoria");
                }
            }
            if (posicao_ultima == tamanho_vetor - 1){
                alocarVetor();
            }
            vetor[++posicao_ultima] = elemento;
        }
};