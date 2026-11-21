
#ifndef DOMAIN_H
#define DOMAIN_H

#define MAX_SURGERIES 100
#define MAX_SURGEONS 50
#define MAX_THEATRES 30
#define MAX_EQUIPMENT 100

typedef struct {
    int id;
    char name[50];
    char type[50];
    int quantity;
    int available;
} Equipment;

typedef struct {
    int id;
    char name[50];
    char specialization[50];
    int available;
} Surgeon;

typedef struct {
    int id;
    char name[50];
    int capacity;
    int available;
} OperatingTheatre;

typedef struct {
    int id;
    char name[50];

    int duration;
    int priority;
    int start_time;
    int end_time;

    char required_specialization[50];

    int surgeon_id;
    int theatre_id;

    int equipment_required;

    int scheduled;
} Surgery;

typedef struct {
    Surgery surgeries[MAX_SURGERIES];
    Surgeon surgeons[MAX_SURGEONS];
    OperatingTheatre theatres[MAX_THEATRES];
    Equipment equipment[MAX_EQUIPMENT];

    int surgery_count;
    int surgeon_count;
    int theatre_count;
    int equipment_count;
} Hospital;

void initializeHospital(Hospital *hospital);

int addSurgery(Hospital *hospital, Surgery surgery);
int addSurgeon(Hospital *hospital, Surgeon surgeon);
int addTheatre(Hospital *hospital, OperatingTheatre theatre);
int addEquipment(Hospital *hospital, Equipment equipment);

void displaySurgeries(const Hospital *hospital);
void displaySurgeons(const Hospital *hospital);
void displayTheatres(const Hospital *hospital);
void displayEquipment(const Hospital *hospital);

#endif
