#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

typedef struct{
    char name[20];
    char keywords[10][20];
    int numkeywords;
    int importancia;
}Site;

Site *createSite(const char *name) {
    Site *site = (Site *)malloc(sizeof(Site));
    if (site) {
        strncpy(site->name, name, 20);
        site->numkeywords = 0;
        site->importancia = 0;
    }
    return site;
}

void addKeyword(Site *site, const char *keyword) {
    if (site->numkeywords < 10) {
        strncpy(site->keywords[site->numkeywords], keyword, 20);
        site->numkeywords++;
    }
}

void searchByKeyword(Graph *g, const char *keyword) {
    Vertex *v = g->first;
    while (v) {
        Site *site = (Site *)v->value;
        for (int i = 0; i < site->numkeywords; i++) {
            if (strcmp(site->keywords[i], keyword) == 0) {
                printf("Site encontrado: %s (Importância: %d)\n", site->name, site->importancia);
                break;
            }
        }
        v = v->next;
    }
}

/*void calculateImportance(Graph *g) { //funcao teste v1
    Vertex *v = g->first;
    while (v) {
        Site *site = (Site *)v->value;
        site->importancia = 0; // Resetar a importância antes de recalcular

        Vertex *currentVertex = g->first;
        while (currentVertex) {
            Edge *e = currentVertex->first;
            while (e) {
                if (e->head == v) {
                    site->importancia += e->value; // Somar o valor da aresta
                }
                e = e->next;
            }
            currentVertex = currentVertex->next;
        }

        v = v->next;
    }
}*/

/*void calculateImportance(Graph *g) {  //funcao teste v2
    // Resetar importância de todos os sites
    Vertex *v = g->first;
    while (v) {
        Site *site = (Site *)v->value;
        site->importancia = 0;
        v = v->next;
    }

    // Percorrer todas as arestas e somar os pesos nos nós de destino
    v = g->first;
    while (v) {
        Edge *e = v->first;
        while (e) {
            Site *destSite = (Site *)e->head->value; // Obtém o site de destino
            destSite->importancia += e->value; // Soma o peso da aresta
            e = e->next;
        }
        v = v->next;
    }
}*/

/*void calculateImportance(Graph *g) {  // funcao teste v3
    // Verificar se o grafo é válido
    if (!g) {
        printf("Erro: Grafo não inicializado.\n");
        return;
    }

    // Resetar a importância de todos os sites
    Vertex *v = g->first;
    while (v) {
        Site *site = (Site *)v->value;
        site->importancia = 0;
        v = v->next;
    }

    // Percorrer todas as arestas e somar os pesos nos nós de destino
    v = g->first;
    while (v) {
        Edge *e = v->first;
        while (e) {
            if (e->head) { 
                Site *destSite = (Site *)e->head->value; // Obtém o site de destino
                destSite->importancia += e->value; // Soma o peso da aresta
                
                // Mensagem de depuração
                printf("Somando peso %d para %s\n", e->value, destSite->name);
            } else {
                printf("Erro: Aresta sem destino.\n");
            }
            e = e->next;
        }
        v = v->next;
    }
}*/

void calculateImportance(Graph *g) {
    if (!g) {
        printf("Erro: Grafo não inicializado.\n");
        return;
    }

    // Resetar todas as importâncias antes de calcular
    Vertex *v = g->first;
    while (v) {
        Site *site = (Site *)v->value;
        site->importancia = 0;
        v = v->next;
    }

    // Percorrer todas as arestas e somar os pesos para os sites de destino
    v = g->first;
    while (v) {
        Edge *e = v->first;
        while (e) {
            if (e->head) { 
                Site *destSite = (Site *)e->head->value; // Site de destino
                destSite->importancia += e->value; // Somar o peso da aresta
                
                // Mensagem de depuração detalhada
                printf("Somando peso %d para %s (Total acumulado: %d)\n", 
                        e->value, destSite->name, destSite->importancia);
            } else {
                printf("Erro: Aresta sem destino.\n");
            }
            e = e->next;
        }
        v = v->next;
    }
}



void printImportances(Graph *g) {
    Vertex *v = g->first;
    while (v) {
        Site *site = (Site *)v->value;
        printf("Site: %s - Importância: %d\n", site->name, site->importancia);
        v = v->next;
    }
}

void inicializateStnoGraph(Graph *graph){
    Site *s1 = createSite("opiniao.com");
    addKeyword(s1, "jogo");
    addKeyword(s1, "melhor");
    addKeyword(s1, "computador");
    addKeyword(s1, "console");
    addKeyword(s1, "smartphone");
    addKeyword(s1, "tecnologia");
    
    Site *s2 = createSite("wiki.com");
    addKeyword(s2, "computador");
    addKeyword(s2, "hardware");
    addKeyword(s2, "smartphone");
    addKeyword(s2, "ator");
    addKeyword(s2, "filme");
    addKeyword(s2, "tecnologia");

    Site *s3 = createSite("games.com");
    addKeyword(s3, "computador");
    addKeyword(s3, "preco");
    addKeyword(s3, "jogo");
    addKeyword(s3, "console");
    addKeyword(s3, "promocao");
    addKeyword(s3, "on-line");

    Site *s4 = createSite("hardware.com");
    addKeyword(s4, "tecnologia");
    addKeyword(s4, "computador");
    addKeyword(s4, "hardware");
    addKeyword(s4, "peca");
    addKeyword(s4, "manutencao");
    addKeyword(s4, "preco");

    Site *s5 = createSite("shopping.com");
    addKeyword(s5, "computador");
    addKeyword(s5, "promocao");
    addKeyword(s5, "preco");
    addKeyword(s5, "console");
    addKeyword(s5, "smartphone");
    addKeyword(s5, "calcado");

    Site *s6 = createSite("videos.com");
    addKeyword(s6, "tecnologia");
    addKeyword(s6, "noticia");
    addKeyword(s6, "filme");
    addKeyword(s6, "futebol");
    addKeyword(s6, "console");
    addKeyword(s6, "melhor");
    
    Site *s7 = createSite("bet.com");
    addKeyword(s7, "jogo");
    addKeyword(s7, "aposta");
    addKeyword(s7, "promocao");
    addKeyword(s7, "premiacao");
    addKeyword(s7, "on-line");
    addKeyword(s7, "preco");
    
    Site *s8 = createSite("tv.com");
    addKeyword(s8, "noticia");
    addKeyword(s8, "entrevista");
    addKeyword(s8, "filme");
    addKeyword(s8, "ator");
    addKeyword(s8, "serie");
    addKeyword(s8, "jogo");

    Site *s9 = createSite("jornal.com");
    addKeyword(s9, "noticia");
    addKeyword(s9, "entrevista");
    addKeyword(s9, "manchete");
    addKeyword(s9, "on-line");
    addKeyword(s9, "materia");
    addKeyword(s9, "filme");

    Site *s10 = createSite("esporte.com");
    addKeyword(s10, "jogo");
    addKeyword(s10, "futebol");
    addKeyword(s10, "resultado");
    addKeyword(s10, "on-line");
    addKeyword(s10, "entrevista");
    addKeyword(s10, "melhor");

    Graph_insertVertex(graph, 1, s1); //opniao
    Graph_insertVertex(graph, 2, s2); //wiki
    Graph_insertVertex(graph, 3, s3); //games
    Graph_insertVertex(graph, 4, s4); //hardware
    Graph_insertVertex(graph, 5, s5); //shopping
    Graph_insertVertex(graph, 6, s6); //videos
    Graph_insertVertex(graph, 7, s7); //bet
    Graph_insertVertex(graph, 8, s8); //tv
    Graph_insertVertex(graph, 9, s9); //jornal
    Graph_insertVertex(graph, 10, s10); //esporte

    Graph_insertEdge(graph, 1, 2, 1); //opiniao -> wiki
    Graph_insertEdge(graph, 1, 3, 1); //opiniao -> games

    Graph_insertEdge(graph, 3, 7, 3); //games -> bet
    Graph_insertEdge(graph, 3, 6, 3); //games -> videos
    Graph_insertEdge(graph, 3, 4, 3); //games -> hardware
    
    Graph_insertEdge(graph, 4, 5, 2); //hardware -> shopping
    Graph_insertEdge(graph, 4, 6, 2); //hardware -> videos
    Graph_insertEdge(graph, 4, 7, 2); //hardware -> bet
    Graph_insertEdge(graph, 4, 2, 2); //hardware -> wiki
    Graph_insertEdge(graph, 4, 3, 2); //hardware -> games

    Graph_insertEdge(graph, 5, 6, 3); //shopping -> videos

    Graph_insertEdge(graph, 6, 5, 7); //videos -> shopping
    Graph_insertEdge(graph, 6, 7, 7); //videos -> bet

    Graph_insertEdge(graph, 7, 10, 4); //bet -> esporte

    Graph_insertEdge(graph, 8, 5, 1); //tv -> shopping
    Graph_insertEdge(graph, 8, 6, 1); //tv -> videos
    Graph_insertEdge(graph, 8, 9, 1); //tv -> jornal

    Graph_insertEdge(graph, 9, 6, 2); //jornal -> videos
    Graph_insertEdge(graph, 9, 10, 2); //jornal -> esporte

    Graph_insertEdge(graph, 10, 6, 2); //esporte -> videos
    Graph_insertEdge(graph, 10, 9, 2); //esporte -> jornal
}

int main(){
    Graph *gph = Graph_alloc();
    inicializateStnoGraph(gph);
    //Graph_print(gph);

    
    
    calculateImportance(gph);
    printf("\n\n");
    printImportances(gph);

    searchByKeyword(gph, "computador");
}
/* 
opiniao 0    -
wiki 3       -
games 3 
hardware 3   -
shopping 10 
videos 13    -
bet 12       -
tv 0         -
jornal 3
esporte 6    -
*/

