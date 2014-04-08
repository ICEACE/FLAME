FLAME
=====
A Multi-agent Implementation of ICEACE Model in FLAME. 

Software License
================
FLAME implementation of ICEACE project is developed and maintained by Bulent Ozel (bulent.ozel@gmail.com). Other contributors are Einar Jon Erlingsson and Marco Raberto.

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.

Project Summary
===============
ICEACE (Financial instability, credit rationing and business cycles in an agent-based model: the case of Iceland)
is funded by The Icelandic Research Fund 2011.

The project has a twofold goal. From a scientific perspective, it aims to understand the endogenous sources of
instability in the financial system and to devise the relationship between credit supply, assets bubble and
macroeconomic activity. In order to achieve this goal, the project foresees the development of an agent-based
model and a simulator of a credit network economy. From a more practical and societal perspective, the second
objective of the project is the calibration and validation of the simulator on the Icelandic economy so to make it
an innovative and powerful computational facility for the assessment of economic scenarios and the design of
policy measures. Particularly for macroeconomic policy and systemic risk assessment. The project aims to
fully adopt the agent-based approach in order to overcome the limitations that usually affect the large scale
macro-econometric models as well as the dynamic stochastic general equilibrium models, which are now employed
at policy institutions.

FLAME (Flexible Large-scale Agent Modelling Environment) is an agent-based modelling system.
It serves as the major multi-agent platform for the implementation of ICEACE model.

Repository Files
================
This root folder holds model description (model_iceace file) and top level agent functions.
It needs to parsed with xparser and compiled afterwards in order to run the model on a local machine.

model_aname.xml: Top level model descriptions.

agentname_functions_context.c : Describes an agent behaviour within a context, i.e., market.

./Market_Amarketname: Folder containing market model and market specific agent functions at Amarketname.

./docs: The folder containing implementation related documents.

./initialization: The folder containing various initial populations.

./outputs: Holds sample outputs of data, scripts, snapshots of iterations, and plots.

