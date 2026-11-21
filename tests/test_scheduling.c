
#include <stdio.h>
#include <assert.h>
#include "domain.h"
#include "scheduling.h"

int main(void) {
    Hospital h;
    initializeHospital(&h);

    Surgeon surgeon = {0};
    surgeon.id = 101;
    snprintf(surgeon.name, sizeof(surgeon.name), "Dr. Sharma");
    surgeon.available = 1;
    addSurgeon(&h, surgeon);

    OperatingTheatre theatre = {0};
    theatre.id = 201;
    snprintf(theatre.name, sizeof(theatre.name), "OT-1");
    theatre.capacity = 10;
    theatre.available = 1;
    addTheatre(&h, theatre);

    Surgery s1 = {0};
    s1.id = 1;
    snprintf(s1.name, sizeof(s1.name), "Heart Surgery");
    s1.duration = 60;
    s1.priority = 5;
    s1.start_time = 540;
    s1.equipment_required = 2;
    addSurgery(&h, s1);

    Surgery s2 = {0};
    s2.id = 2;
    snprintf(s2.name, sizeof(s2.name), "Eye Surgery");
    s2.duration = 30;
    s2.priority = 3;
    s2.start_time = 610;
    s2.equipment_required = 1;
    addSurgery(&h, s2);

    scheduleSurgeries(&h);

    assert(h.surgeries[0].scheduled == 1);
    assert(h.surgeries[0].surgeon_id == 101);
    assert(h.surgeries[0].theatre_id == 201);
    assert(h.surgeries[0].end_time == 600);

    assert(h.surgeries[1].scheduled == 1);
    assert(h.surgeries[1].end_time == 640);

    printf("All priority scheduling tests passed!\n");

    return 0;
}
