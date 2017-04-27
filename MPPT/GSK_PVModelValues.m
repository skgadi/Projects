% Constants taken from E20/435 SOLAR PANEL
% file:///C:/Users/gadis/Downloads/ds-e20-series-435-solar-panel-datasheet.pdf

T_n = 25+273;
G_n = 1000;
K_I = 3.5e-3; % Unit is Amps/Kelvin
I_pv_n = 6.5; % Approximate value
K_V = - 235.5e-3; % Unit is volts/Kelvin
I_sc_n = 6.43;
V_oc_n = 85.6;
N_s = 128; % Number of cells connected in series

a = 1.5; % Ideality factor

R_s = 1e-3*128;
R_p = 1000;

k = physconst('Boltzmann');
q = 1.60217662e-19;


T = 273+40;