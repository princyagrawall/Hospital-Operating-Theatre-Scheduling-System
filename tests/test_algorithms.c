
#include <stdio.h>
#include <assert.h>
#include "domain.h"
#include "scheduling.h"

int main(void) {
    Hospital h;
    initializeHospital(&h);

    /* Create one available theatre */
    OperatingTheatre theatre = {0};
    theatre.id = 1;
    theatre.capacity = 10;
    theatre.available = 1;
    addTheatre(&h, theatre);

    /* Add three non-overlapping surgeries */
    Surgery s1 = {0};
    s1.id = 1;
    snprintf(s1.name, sizeof(s1.name), "Surgery A");
    s1.start_time = 540;
    s1.duration = 60;
    s1.equipment_required = 2;
    addSurgery(&h, s1);

    Surgery s2 = {0};
    s2.id = 2;
    snprintf(s2.name, sizeof(s2.name), "Surgery B");
    s2.start_time = 600;
    s2.duration = 45;
    s2.equipment_required = 2;
    addSurgery(&h, s2);

    Surgery s3 = {0};
    s3.id = 3;
    snprintf(s3.name, sizeof(s3.name), "Surgery C");
    s3.start_time = 645;
    s3.duration = 30;
    s3.equipment_required = 2;
    addSurgery(&h, s3);

    scheduleUsingIntervalPartitioning(&h);

    assert(h.surgeries[0].scheduled == 1);
    assert(h.surgeries[1].scheduled == 1);
    assert(h.surgeries[2].scheduled == 1);

    assert(h.surgeries[0].theatre_id == 1);
    assert(h.surgeries[1].theatre_id == 1);
    assert(h.surgeries[2].theatre_id == 1);

    printf("\nAll interval scheduling algorithm tests passed!\n");

    return 0;
}
