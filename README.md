FLAME
=====

A Multi-agent Implementation of ICEACE Model in FLAME. 


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

This root folder holds model description (model_vn.n.n.xml file) and agent functions.
It needs to parsed with xparser and compiled afterwards in order to run the model on a local machine.

model_vn.n.n.xml: model descriptions.

agentname_functions_context.c : Describes an agent behaviour within a context, i.e., market.

changelog.txt: holds information on major changes.

./Market_amarketname: folder containing market model and market specific agent functions at amarketname.

./docs: a folder containing implementation related documents.

./outputs: holds sample outputs of latest version.

./outputs/0.xml : holds initial states of described model.


