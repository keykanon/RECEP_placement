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
simple ConsumerNode extends MobileNode
{
    parameters:
        @class(ConsumerNode);
        @display("i=block/broadcast");
        double speed @unit("mps") = default(10mps);  // the speed of the mobile nodes
        double distance @unit("m") = default(5m);      // switch to the next waypoint if the current waypoint target is closer than this
        string trackFile;                            // a file with longitude latitude pairs
}
