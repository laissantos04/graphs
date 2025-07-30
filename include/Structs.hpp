#include <vector>
#include <string>

/* Estruturas auxiliares para os algoritmos */

/* Estrutura para o algoritmo de busca em profundidade */

struct DFSResult{
    std::vector<int> parent, time_in, time_out, low_v;
    std::vector<std::string> color_v; 
    int timer = 0; 

    /* Inicializa os vetores com os valores padrão */
    void init(int n) {
        parent.assign(n, -1);
        time_in.assign(n, 0);
        time_out.assign(n, 0);
        low_v.assign(n, 0);
        color_v.assign(n, "white");
    }
};

