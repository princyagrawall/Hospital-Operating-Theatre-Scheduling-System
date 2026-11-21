
#include <stdio.h>
#include <assert.h>

#include "domain.h"
#include "scheduling.h"

int main(void) {

    /* TEST 1: Empty hospital */
    Hospital hospital;
    initializeHospital(&hospital);

    scheduleUsingBacktracking(&hospital);

    assert(hospital.surgery_count == 0);
    assert(hospital.theatre_count == 0);

    printf("Test 1 passed: Empty hospital.\n");


    /* TEST 2: Surgery without a theatre */
    Surgery s1 = {0};

    s1.id = 1;
    s1.duration = 60;
    s1.start_time = 540;
    s1.equipment_required = 1;

    assert(addSurgery(&hospital, s1));

    scheduleUsingBacktracking(&hospital);

    assert(hospital.surgeries[0].scheduled == 0);

    printf("Test 2 passed: No theatre available.\n");


    /* TEST 3: Two overlapping surgeries */
    Hospital hospital2;
    initializeHospital(&hospital2);

    OperatingTheatre t1 = {0};
    t1.id = 1;
    t1.capacity = 5;
    t1.available = 1;

    assert(addTheatre(&hospital2, t1));

    Surgery s2 = {0};
    s2.id = 2;
    s2.duration = 120;
    s2.start_time = 540;
    s2.equipment_required = 1;

    Surgery s3 = {0};
    s3.id = 3;
    s3.duration = 90;
    s3.start_time = 600;
    s3.equipment_required = 1;

    assert(addSurgery(&hospital2, s2));
    assert(addSurgery(&hospital2, s3));

    scheduleUsingBacktracking(&hospital2);

    assert(hospital2.surgeries[0].scheduled == 1);
    assert(hospital2.surgeries[1].scheduled == 0);

    printf("Test 3 passed: Overlapping surgeries handled.\n");


    /* TEST 4: Non-overlapping surgeries */
    Hospital hospital3;
    initializeHospital(&hospital3);

    OperatingTheatre t2 = {0};
    t2.id = 1;
    t2.capacity = 5;
    t2.available = 1;

    assert(addTheatre(&hospital3, t2));

    Surgery s4 = {0};
    s4.id = 4;
    s4.duration = 60;
    s4.start_time = 540;
    s4.equipment_required = 1;

    Surgery s5 = {0};
    s5.id = 5;
    s5.duration = 60;
    s5.start_time = 600;
    s5.equipment_required = 1;

    assert(addSurgery(&hospital3, s4));
    assert(addSurgery(&hospital3, s5));

    scheduleUsingBacktracking(&hospital3);

    assert(hospital3.surgeries[0].scheduled == 1);
    assert(hospital3.surgeries[1].scheduled == 1);

    printf("Test 4 passed: Non-overlapping surgeries share a theatre.\n");

    printf("\nAll scheduling tests completed.\n");

    return 0;
}
