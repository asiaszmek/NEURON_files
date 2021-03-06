These are supplement files for the NEURON model used in my PLoSCB 2017 manuscript.<br>
To run the model, type `nrngui` in commandline to run [the NEURON simulator][1]. Type in or copy paste the command from `main.hoc` line by line. So you can visualize the voltage from soma section.<br>

All ion conductance parameters are in `params.txt`. See the file `params.notes` for what each parameter represents.<br>
The pyramidal cell morphology can be retrieved from `n400td-pc2-sp-axn.hoc`.<br>
The directory `ca1n1-mod` contains all `.mod` files for ion channels, including various Na+ channels, K+ channels, Ca2+ channels, and so on. The x86_64 folder contains all those compiled mod files for Unix 64bit OS. The synaptic release mechansim is coded in `expsyn2c.mod`.<br>

Synaptic release is probabilistic, following a probability profile measured in [an electrophysiology experiment study][2]. The probability is stored in the file `relpr_smooth_col4.dat`.<br>

There are in 190 spines in total. Synapse release patterns can be adjusted using the function `syn_set_col4()` in `syn.hoc` file. The parameters for the function are the total number of synaptic stimulation, the number of stimulations in each action potential bursts (for Theta burst), number of AMPARs in each spine, number of NMDARs, the short interval between synapstic stimulation within a burst (in ms), and the long interval between consecutive groups of bursts (in ms). As an example, these parameter values can be 150, 5 200, 10, 10, 250, respectively, which generats an equvalent of 4 Hz Theta bursts stimulations. 

[1]: https://www.neuron.yale.edu/neuron/
[2]: http://jn.physiology.org/content/jn/108/7/1965.full.pdf