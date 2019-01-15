//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package recep_placement.EdgeNetwork;

import recep_placement.Operator.Operator;
import recep_placement.EdgeNetwork.EdgeNode.EdgeNode;
import recep_placement.User.ConsumerNode;
import recep_placement.User.ConnectionController;
import recep_placement.User.IoTScene;

channel Link extends ned.DatarateChannel {
    parameters:
        int cost = default(0);
        delay = 0ms;//uniform(10ms,25ms);
        datarate = uniform(10Mbps,20Mbps);
}

network Net
{
    parameters:
        int nodeNum = 10;
    	@display("bgb=396,217");
    	@figure[car](type=image; image="car-top-view"; pos=0,0; anchor=c);	
    	int numConsumers = default(0); // the number of consumers on the street;
    submodules:
        node[10]: EdgeNode {
            Naddress = index;
            capacity = 10;
        }
        
        consumer[numConsumers]: ConsumerNode{
            @display("p=243,150");
        }
        
        connectionController: ConnectionController {
         	   @display("p=243,31");
        }
		
		//scene: IoTScene{
		//    @display("p=74,31");
		//}
    connections:
        node[0].g++ <--> Link <--> node[1].g++;
        node[0].g++ <--> Link <--> node[5].g++;
        node[0].g++ <--> Link <--> node[6].g++;
        node[1].g++ <--> Link <--> node[2].g++;
        node[1].g++ <--> Link <--> node[3].g++;
        node[1].g++ <--> Link <--> node[5].g++;
        node[2].g++ <--> Link <--> node[4].g++;
        node[2].g++ <--> Link <--> node[7].g++;
        node[2].g++ <--> Link <--> node[8].g++;
        node[3].g++ <--> Link <--> node[7].g++;
        node[4].g++ <--> Link <--> node[7].g++;
        node[4].g++ <--> Link <--> node[8].g++;
        node[5].g++ <--> Link <--> node[6].g++;
        node[5].g++ <--> Link <--> node[9].g++;
        node[7].g++ <--> Link <--> node[9].g++;
        
}
