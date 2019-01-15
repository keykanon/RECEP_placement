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

import recep_placement.User.ConsumerNode;
import recep_placement.User.IoTScene;

package recep_placement.EdgeNetwork;

network TestNet
{
    parameters:
        @figure[car](type=image; image="car-top-view"; pos=10,10; anchor=c);
        int numConsumers = default(0); // the number of consumers on the street;
        @display("bgb=421,222");
    submodules:
        consumer[numConsumers]: ConsumerNode {
            @display("p=61,42");
        }
        
}
