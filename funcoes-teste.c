
void calculateImportance(Graph *g) {  //funcao teste v2
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
}

void calculateImportance(Graph *g) {  // funcao teste v3
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
}

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


----------------

void printImportances(Graph *g) {
    Vertex *v = g->first;
    while (v) {
        Site *site = (Site *)v->value;
        printf("Site: %s - Importância: %d\n", site->name, site->importancia);
        v = v->next;
    }
}

void printEdges(Graph *g) {
    Vertex *v = g->first;
    while (v) {
        Site *site = (Site *)v->value;
        Edge *e = v->first;
        while (e) {
            Site *dest = (Site *)e->head->value;
            printf("%s -> %s (peso: %d)\n", site->name, dest->name, e->value);
            e = e->next;
        }
        v = v->next;
    }
}
