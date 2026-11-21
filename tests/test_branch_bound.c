
#include <stdio.h>
#include <assert.h>
#include "domain.h"
#include "scheduling.h"

int main(void) {

    /* TEST 1: Overlapping surgeries - choose higher priority */
    Hospital h1;
    initializeHospital(&h1);

    OperatingTheatre t1 = {0};
    t1.id = 1;
    t1.capacity = 10;
    t1.available = 1;
    addTheatre(&h1, t1);

    Surgery s1 = {0};
    s1.id = 1;
    snprintf(s1.name, sizeof(s1.name), "High Priority");
    s1.start_time = 540;
    s1.duration = 120;
    s1.priority = 10;
    s1.equipment_required = 1;

    Surgery s2 = {0};
    s2.id = 2;
    snprintf(s2.name, sizeof(s2.name), "Low Priority");
    s2.start_time = 600;
    s2.duration = 90;
    s2.priority = 5;
    s2.equipment_required = 1;

    addSurgery(&h1, s1);
    addSurgery(&h1, s2);

    scheduleUsingBranchAndBound(&h1);

    assert(h1.surgeries[0].scheduled == 1);
    assert(h1.surgeries[1].scheduled == 0);

    printf("Test 1 passed: Higher priority surgery selected.\n");


    /* TEST 2: Non-overlapping surgeries */
    Hospital h2;
    initializeHospital(&h2);

    addTheatre(&h2, t1);

    Surgery s3 = {0};
    s3.id = 3;
    snprintf(s3.name, sizeof(s3.name), "Surgery A");
    s3.start_time = 540;
    s3.duration = 60;
    s3.priority = 5;
    s3.equipment_required = 1;

    Surgery s4 = {0};
    s4.id = 4;
    snprintf(s4.name, sizeof(s4.name), "Surgery B");
    s4.start_time = 600;
    s4.duration = 60;
    s4.priority = 8;
    s4.equipment_required = 1;

    addSurgery(&h2, s3);
    addSurgery(&h2, s4);

    scheduleUsingBranchAndBound(&h2);

    assert(h2.surgeries[0].scheduled == 1);
    assert(h2.surgeries[1].scheduled == 1);

    printf("Test 2 passed: Non-overlapping surgeries scheduled.\n");


    /* TEST 3: Insufficient theatre capacity */
    Hospital h3;
    initializeHospital(&h3);

    OperatingTheatre smallTheatre = {0};
    smallTheatre.id = 2;
    smallTheatre.capacity = 1;
    smallTheatre.available = 1;
    addTheatre(&h3, smallTheatre);

    Surgery s5 = {0};
    s5.id = 5;
    s5.duration = 60;
    s5.start_time = 540;
    s5.priority = 10;
    s5.equipment_required = 5;

    addSurgery(&h3, s5);

    scheduleUsingBranchAndBound(&h3);

    assert(h3.surgeries[0].scheduled == 0);

    printf("Test 3 passed: Insufficient theatre capacity handled.\n");

    printf("\nAll Branch and Bound tests passed!\n");

    return 0;
}
