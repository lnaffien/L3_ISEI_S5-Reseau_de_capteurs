/* 50 noeuds eparpilles de facon aleatoire
 * 1000m x 1000m
 * toutes les infos vont vers le noeud 0 (energie initiale illimitee)
 * 5 clusters avec 10 noeuds chacun, dont 1 Cluster Head
 * noeud capteur -> CH -> Noeud Sink (neud de base)
 * fichier trace
 * XML
 */
#include "ns3/netanim-module.h"
#include "ns3/core-module.h"

#define NBR_NODES 50
#define SURFACE_X 1000
#define SURFACE_Y 1000

struct sensor
{  
     short xLoc;        // X-location of sensor  
     short yLoc;        // Y-location of sensor  
     short lPeriods;        // number of periods the sensor  
                // has been in use for  
     short ePeriods;        // expected periods the sensor   
                // must be operational for  
     double bCurrent;       // current battery power  
     double bPower;     // initial battery power  
     double pAverage;       // average power consumed per   
                // transmission period.  
     int round;         // the last round that the sensor   
                // served as a cluster head  
     int head;          // stores the index of the cluster head   
                // for the sensor to transmit to, set to -1 if the   
                // sensor is a cluster head  
     int cluster_members;   // stores the total number of nodes in   
                // the cluster, applicable only for   
                // cluster head nodes  
     int head_count;        // this contains the count of the   
                // number of times a sensor has been   
                // the head of a cluster, can be   
                // removed for optimization later  
}; 

void initializeNetwork(struct sensor network[]);  
// initializes the network; randomly places nodes within   
// the grid and sets battery power to default value 

struct sensor * loadConfiguration(char * filename);  
// loads values for the network initialization  
// including starting battery power, size of network,   
// and number of nodes  
  
int runLeachSimulation(const struct sensor network[]);  
// takes an initialized sensor network and simulates   
// the LEACH protocol on that network  
// The network is unchanged so that the same network   
// can be passed to other simulator functions  
// The function returns the number of rounds for which the   
// average power of the network remained above the threshold.

int runDirectSimulation(const struct sensor network[]);  
// takes an initialized sensor network and simulates  
// the direct transmission protocol wherein all sensors   
// transmit directly to the base station. The network is   
// unchanged so other protocols can be run on it  
// The function returns the number of rounds for which the   
// average power of the network remained above the threshold.  
  
int runDirectSimulationNPP(const struct sensor network[]);  
// takes an initialized sensor network and simulates  
// the direct transmission protocol with the Network Preserving  
// Protocol in place to lengthen network usefulness. The sensors   
// transmit directly to the base station. The network is   
// unchanged so other protocols can be run on it  
// The function returns the number of rounds for which the   
// average power of the network remained above the threshold.  
  
int sensorTransmissionChoice(const struct sensor a);  
// using the NPP, this function determines whether sensor a  
// should transmit in the current round based on the expected  
// number of rounds the network will be in use and the average   
// energy the sensor has used per round thus far in the simulation.  
// Returns 1 if the sensor should transmit, 0 otherwise.  

int runmodification(const sensor network[]);

int main (int argc, char *argv[])
{
    NodeContainer fabrique_de_noeud = NodeContainer.Create(NUM_NODES);

    Simulator::Run ();
    Simulator::Destroy ();
    return 0;
}

void initializeNetwork(struct sensor network[])
{  
// Preconditions:   network is an unitialized sensor network.  
// Postconditions:  network is an initialized sensor network   
//                  whose values are loaded from global varibles   
//          which are set using the loadConfiguration   
//          function or the defaults are used  
    int i = 0;  
    srand((unsigned int) time(0));  
          
    for(i = 0; i < NBR_NODES; i++) {  
                network[i].xLoc = rand() % SURFACE_X;
                network[i].yLoc = rand() % SURFACE_Y;
                network[i].lPeriods = 0;
                network[i].ePeriods = TOTAL_ROUNDS; 
                network[i].pAverage = 0.00;  
        network[i].round = FALSE;  
        network[i].head = FALSE;  
    }  
       
}           // end initializeNetwork function  
  