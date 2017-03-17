/*
 *  graph1.c - the "intuitive" graph representation
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#include <stdlib.h>

#include <C:\\dataStructure\\graph_practise\\graph.h>


MBgraph1 *MBgraph1_create(void)
{
    MBgraph1 *graph = malloc(sizeof(MBgraph1));
    if (graph) {
        graph->vertices = MBset_create((MBcmpfn)MBvertex_compare);
        graph->edges = MBset_create((MBcmpfn)MBedge_compare);
    }
    return graph;
}

void MBgraph1_delete(MBgraph1 *graph)
{
    if (graph) {
        MBset_for_each(graph->vertices, (MBforfn)MBvertex_delete);
        MBset_delete(graph->vertices);
        MBset_for_each(graph->edges, (MBforfn)MBedge_delete);
        MBset_delete(graph->edges);
        free(graph);
    }
}

MBvertex *MBgraph1_add(MBgraph1 *graph, const char *name, void *data)
{
    MBvertex *vertex = MBvertex_create(name, data, NULL, NULL);
    MBvertex *existing = MBset_add(graph->vertices, vertex);
    MBvertex_delete(existing);
    return vertex;
}

MBvertex *MBgraph1_get_vertex(const MBgraph1 *graph, const char *name)
{
    MBvertex *vertex = MBset_find(graph->vertices, &name);
    return vertex;
}

void *MBgraph1_remove(MBgraph1 *graph, MBvertex *vertex)
{
    MBvertex * removed;
    void *data;
    unsigned int e = 0;

    /* Remove the edges belonging to this vertex */
    while (e < MBset_get_count(graph->edges)) {
        MBedge *edge = MBset_get(graph->edges, e);
        if (edge->from == vertex || edge->to == vertex) {
            MBset_remove_at(graph->edges, e);
            MBedge_delete(edge);
        }
        else {
            e++;
        }
    }
    /* Remove the vertex */
    removed = MBset_remove(graph->vertices, vertex);
    if (removed) {
        data = removed->data;
        MBvertex_delete(removed);
    }

    return data;
}

void MBgraph1_add_edge(MBgraph1 *graph, MBvertex *vertex1, MBvertex *vertex2)
{
    MBedge *edge = MBedge_create(vertex1, vertex2);
    MBedge *existing = MBset_add(graph->edges, edge);
    MBedge_delete(existing);
}

void MBgraph1_remove_edge(MBgraph1 *graph, MBvertex *vertex1, MBvertex *vertex2)
{
    unsigned int e;
    unsigned int removed = 0;

    for (e = 0; e < MBset_get_count(graph->edges) && !removed; e++) {
        MBedge *edge = MBset_get(graph->edges, e);
        if (edge->from == vertex1 && edge->to == vertex2) {
            MBset_remove_at(graph->edges, e);
            MBedge_delete(edge);
            removed = 1;
        }
    }
}

unsigned int MBgraph1_get_adjacent(const MBgraph1 *graph, const MBvertex *vertex1, const MBvertex *vertex2)
{
    unsigned int adjacent = 0;
    unsigned int e;

    for (e = 0; e < MBset_get_count(graph->edges) && adjacent == 0; e++) {
        const MBedge *edge = MBset_get(graph->edges, e);
        adjacent = edge->from == vertex1 && edge->to == vertex2;
    }

    return adjacent;
}

typedef struct {
    const MBgraph1 *graph;
    const MBvertex *vertex;
    unsigned int e;
} neighbour_iterator;

static neighbour_iterator *neighbour_iterator_create(const MBgraph1 *graph, const MBvertex *vertex)
{
    neighbour_iterator *it = malloc(sizeof(neighbour_iterator));
    if (it) {
        it->graph = graph;
        it->vertex = vertex;
        it->e = 0;
    }
    return it;
}

static void neighbour_iterator_delete(neighbour_iterator *it)
{
    free(it);
}

static void *neighbour_iterator_get(neighbour_iterator *it)
{
    MBvertex *neighbour = NULL;
    for (;it->e < MBset_get_count(it->graph->edges) && neighbour == NULL; it->e++) {
        const MBedge *edge = MBset_get(it->graph->edges, it->e);
        if (edge->from == it->vertex) {
            neighbour = edge->to;
        }
    }
    return neighbour;
}

MBiterator *MBgraph1_get_neighbours(const MBgraph1 *graph, const MBvertex *vertex)
{
    return MBiterator_create(neighbour_iterator_create(graph, vertex),
        (MBgetfn)neighbour_iterator_get, (MBdeletefn)neighbour_iterator_delete);
}

MBiterator *MBgraph1_get_edges(const MBgraph1 *graph)
{
    return MBset_iterator(graph->edges);
}

MBiterator *MBgraph1_get_vertices(const MBgraph1 *graph)
{
    return MBset_iterator(graph->vertices);
}

unsigned int MBgraph1_get_neighbour_count(const MBgraph1 * graph, const MBvertex * vertex)
{
    /* The neighbour count is the count of edges that are from this vertex */
    unsigned int e;
    unsigned int edges = 0;

    for (e = 0; e < MBset_get_count(graph->edges); e++) {
        const MBedge *edge = MBset_get(graph->edges, e);
        edges += edge->from == vertex;
    }

    return edges;
}

unsigned int MBgraph1_get_edge_count(const MBgraph1 * graph)
{
    return MBset_get_count(graph->edges);
}

unsigned int MBgraph1_get_vertex_count(const MBgraph1 * graph)
{
    return MBset_get_count(graph->vertices);
}
