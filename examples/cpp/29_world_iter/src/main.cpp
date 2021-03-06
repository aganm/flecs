#include <world_iter.h>
#include <iostream>

/* Component types */
struct Position {
    double x, y;
};

struct Velocity {
    double x, y;
};

int main(int argc, char *argv[]) {
    /* Create the world, pass arguments for overriding the number of threads,fps
     * or for starting the admin dashboard (see flecs.h for details). */
    flecs::world ecs(argc, argv);

    ecs.entity("E1")
        .set<Position>({10, 20})
        .set<Velocity>({1, 1});

    ecs.entity("E2")
        .set<Position>({30, 40})
        .set<Velocity>({1, 1});    

    for (auto it : ecs) {
        flecs::type table_type = it.table_type();
        std::cout << "Iterating table [" << table_type.str() << "]" 
                  << " (" << it.count() << " entities)" << std::endl;
    }
}
