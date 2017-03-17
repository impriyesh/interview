typedef struct {
    MBvertex *from;
    MBvertex *to;
} MBedge;

const MBvertex * MBedge_get_from(const MBedge * edge);
//Get the vertex that is the starting-point of an edge
const MBvertex * MBedge_get_to(const MBedge * edge);
//Get the vertex that is the end-point of an edge
