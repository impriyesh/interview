typedef struct {
    char * name;
    void * data;
    void * body;
    MBdeletefn deletefn;
} MBvertex;

const char * MBvertex_get_name(const MBvertex *vertex);
//Get the vertex's name
void * MBvertex_get_data(const MBvertex *vertex);
//Get the data associated with a vertex

