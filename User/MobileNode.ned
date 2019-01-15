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

package recep_placement.User;

//
// TODO auto-generated module
//
simple MobileNode
{
    parameters:
        @display("i=block/broadcast");
        @figure[car](type=image; image="car-top-view"; pos=0,0; anchor=c);	
        double timeStep @unit("s") = default(60ms);  // the time granularity of movement calculation (for 30fps)
		double txRange @unit("m") = default(500m);   // the transmission range of the mobile node's radio
		bool showTxRange = default(true);  			// whether to show the transmission range around the node     

}
