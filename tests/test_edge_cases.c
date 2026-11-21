
#include <stdio.h>
#include <assert.h>
#include "domain.h"
#include "scheduling.h"

int main(void) {
    Hospital h;
    initializeHospital(&h);

    /* Test 1: Empty hospital */
    scheduleSurgeries(&h);
    assert(h.surgery_count == 0);

    /* Test 2: No available theatre */
    Surgeon surgeon = {0};
    surgeon.id = 1;
    surgeon.available = 1;
    addSurgeon(&h, surgeon);

    Surgery s = {0};
    s.id = 10;
    snprintf(s.name, sizeof(s.name), "Test Surgery");
    s.duration = 60;
    s.priority = 5;
    s.start_time = 540;
    addSurgery(&h, s);

    scheduleSurgeries(&h);
    assert(h.surgeries[0].scheduled == 0);

    /* Test 3: Unavailable theatre */
    OperatingTheatre theatre = {0};
    theatre.id = 1;
    theatre.capacity = 10;
    theatre.available = 0;
    addTheatre(&h, theatre);

    scheduleSurgeries(&h);
    assert(h.surgeries[0].scheduled == 0);

    /* Test 4: Insufficient theatre capacity */
    h.theatres[0].available = 1;
    h.theatres[0].capacity = 0;
    h.surgeries[0].equipment_required = 5;

    scheduleSurgeries(&h);
    assert(h.surgeries[0].scheduled == 0);

    /* Test 5: Null hospital pointer */
    scheduleSurgeries(NULL);

    printf("\nAll edge case tests passed!\n");

    return 0;
}
