/*
 *  graph1.h - the "intuitive" graph representation
 *  Copyright (C) 2010 Martin Broadhurst
 *  www.martinbroadhurst.com
 */

#ifndef GRAPH1_H
#define GRAPH1_H

#include <vertices.h>
#include <edges.h>
#include <set.h>
#include <iterator.h>

typedef struct {
    MBset * vertices;
    MBset * edges;
} MBgraph1;

MBgraph1 *   MBgraph1_create(void);
void         MBgraph1_delete(MBgraph1 *graph);
MBvertex *   MBgraph1_add(MBgraph1 *graph, const char *name, void *data);
MBvertex *   MBgraph1_get_vertex(const MBgraph1 *graph, const char *name);
void *       MBgraph1_remove(MBgraph1 *graph, MBvertex *vertex);
void         MBgraph1_add_edge(MBgraph1 *graph, MBvertex *vertex1, MBvertex *vertex2);
void         MBgraph1_remove_edge(MBgraph1 *graph, MBvertex *vertex1, MBvertex *vertex2);
unsigned int MBgraph1_get_adjacent(const MBgraph1 *graph, const MBvertex *vertex1, const MBvertex *vertex2);
MBiterator * MBgraph1_get_neighbours(const MBgraph1 *graph, const MBvertex *vertex);
MBiterator * MBgraph1_get_edges(const MBgraph1 *graph);
MBiterator * MBgraph1_get_vertices(const MBgraph1 *graph);
unsigned int MBgraph1_get_neighbour_count(const MBgraph1 * graph, const MBvertex * vertex);
unsigned int MBgraph1_get_edge_count(const MBgraph1 * graph);
unsigned int MBgraph1_get_vertex_count(const MBgraph1 * graph);

#endif /* GRAPH1_H */
