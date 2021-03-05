# qucs/componenets library

add_compile_definitions(${Qt6Widgets_COMPILE_DEFINITIONS}
  ${Qt6Core5Compat_COMPILE_DEFINITIONS}
  ${Qt6Core_COMPILE_DEFINITIONS}
  ${Qt6Gui_COMPILE_DEFINITIONS})

INCLUDE_DIRECTORIES( ${CMAKE_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${Qt6Widgets_INCLUDE_DIRS}
  ${Qt6Core5Compat_INCLUDE_DIRS}
  ${Qt6Core_INCLUDE_DIRS}
  ${Qt6Gui_INCLUDE_DIRS})

SET(COMPONENTS_SRCS
  digi_sim.cpp
  relais.cpp
  resistor.cpp
  diode.cpp
  ac_sim.cpp
  ampere_ac.cpp
  ipulse.cpp
  vexp.cpp
  irect.cpp
  optimizedialog.cpp
  jfet.cpp
  volt_ac.cpp
  volt_dc.cpp
  libcomp.cpp
  param_sweep.cpp
  vprobe.cpp
  vpulse.cpp
  dc_sim.cpp
  vrect.cpp
  ampere_dc.cpp
  eqndefined.cpp
  equation.cpp
  mosfet.cpp
  mosfet_sub.cpp
  spicedialog.cpp
  spicefile.cpp
  ground.cpp
  subcircuit.cpp
  subcirport.cpp
  bjt.cpp
  hb_sim.cpp
  bjtsub.cpp
  capacitor.cpp
  cccs.cpp
  ccvs.cpp
  tr_sim.cpp
  iexp.cpp
  component.cpp
  vccs.cpp
  componentdialog.cpp
  inductor.cpp
  vcvs.cpp
  iprobe.cpp
  opamp.cpp
  #  DLS_1ton.cpp
  #  dff_SR.cpp
  #  logical_buf.cpp
  #  potentiometer.cpp
  #  DLS_nto1.cpp
  #  diac.cpp
  #  logical_inv.cpp
  #  rectline.cpp
  #  EKV26MOS.cpp
  #  logical_nand.cpp
  #  digi_source.cpp
  #  logical_nor.cpp
  #  MESFET.cpp
  #  logical_or.cpp
  #  rfedd.cpp
  #  dmux2to4.cpp
  #  logical_xnor.cpp
  #  rfedd2p.cpp
  #  am_modulator.cpp
  #  dmux3to8.cpp
  #  logical_xor.cpp
  #  rlcg.cpp
  #  dmux4to16.cpp
  #  mod_amp.cpp
  #  rs_flipflop.cpp
  #  ecvs.cpp
  #module.cpp
  #  source_ac.cpp
  #  ampere_noise.cpp
  #  sp_sim.cpp
  #  amplifier.cpp
  #  etr_sim.cpp
  #  fa1b.cpp
  #  sparamfile.cpp
  #  andor4x2.cpp
  #  fa2b.cpp
  #  mscorner.cpp
  #  andor4x3.cpp
  #  gatedDlatch.cpp
  #  mscoupled.cpp
  #  andor4x4.cpp
  #  greytobinary4bit.cpp
  #  mscross.cpp
  #  attenuator.cpp
  #  msgap.cpp
  #  biast.cpp
  #  gyrator.cpp
  #  mslange.cpp
  #  binarytogrey4bit.cpp
  #  ha1b.cpp
  #  msline.cpp
  #  msmbend.cpp
  #  substrate.cpp
  #  msopen.cpp
  #  switch.cpp
  #  bondwire.cpp
  #  msrstub.cpp
  #  symtrafo.cpp
  #  msstep.cpp
  #  tff_SR.cpp
  #  mstee.cpp
  #  thyristor.cpp
  #  msvia.cpp
  #  tline.cpp
  #  mutual.cpp
  #  tline_4port.cpp
  #  mutual2.cpp
  #  circulator.cpp
  #  mux2to1.cpp
  #  transformer.cpp
  #  coaxialline.cpp
  #  mux4to1.cpp
  #  triac.cpp
  #  comp_1bit.cpp
  #  hpribin4bit.cpp
  #  mux8to1.cpp
  #  tunneldiode.cpp
  #  comp_2bit.cpp
  #  hybrid.cpp
  #  nigbt.cpp
  #  twistedpair.cpp
  #  comp_4bit.cpp
  #  noise_ii.cpp
  #  vafile.cpp
  #  ifile.cpp
  #  noise_iv.cpp
  #  noise_vv.cpp
  #  verilogfile.cpp
  #  vcresistor.cpp
  #  coplanar.cpp
  #  opt_sim.cpp
  #  coupler.cpp
  #  vfile.cpp
  #  cpwgap.cpp
  #  isolator.cpp
  #  vhdlfile.cpp
  #  cpwopen.cpp
  #  pad2bit.cpp
  #  cpwshort.cpp
  #  jk_flipflop.cpp
  #  pad3bit.cpp
  #  cpwstep.cpp
  #  jkff_SR.cpp
  #  pad4bit.cpp
  #  volt_noise.cpp
  #  ctline.cpp
  #  d_flipflop.cpp
  #  log_amp.cpp
  #  phaseshifter.cpp
  #  logic_0.cpp
  #  photodiode.cpp
  #  dcblock.cpp
  #  logic_1.cpp
  #  phototransistor.cpp
  #  dcfeed.cpp
  #  logical_and.cpp
  #  pm_modulator.cpp
  #  vcresistor.cpp
  #vacomponent.cpp
  #  mutualx.cpp

  # SPICE devices

  #  bsim3v34nMOS.cpp
  #  bsim3v34pMOS.cpp
  #  bsim4v30nMOS.cpp
  #  bsim4v30pMOS.cpp
  #  hic0_full.cpp
  #  hic2_full.cpp
  #  hicumL0V1p2.cpp
  #  hicumL0V1p2g.cpp
  #  hicumL0V1p3.cpp
  #  hicumL2V2p1.cpp
  #  hicumL2V2p23.cpp
  #  hicumL2V2p24.cpp
  #  hicumL2V2p31n.cpp
  #  HBT_X.cpp
  )

SET(COMPONENTS_HDRS
  ac_sim.h
  ampere_ac.h
  ampere_dc.h
  bjt.h
  bjtsub.h
  capacitor.h
  cccs.h
  ccvs.h
  component.h
  componentdialog.h
  tr_sim.h
  vccs.h
  vcvs.h
  vexp.h
  volt_ac.h
  volt_dc.h
  vprobe.h
  vpulse.h
  vrect.h
  dc_sim.h
  digi_sim.h
  diode.h
  eqndefined.h
  equation.h
  ground.h
  hb_sim.h
  iexp.h
  inductor.h
  iprobe.h
  ipulse.h
  irect.h
  jfet.h
  libcomp.h
  mosfet_sub.h
  mosfet.h
  opamp.h
  optimizedialog.h
  param_sweep.h
  relais.h
  resistor.h
  spicedialog.h
  spicefile.h
  subcircuit.h
  subcirport.h
  #  am_modulator.h
  #  ampere_noise.h
  #  amplifier.h
  #  andor4x2.h
  #  andor4x3.h
  #  andor4x4.h
  #  attenuator.h
  #  biast.h
  #  binarytogrey4bit.h
  #  bondwire.h
  #  circulator.h
  #  coaxialline.h
  #  comp_1bit.h
  #  comp_2bit.h
  #  comp_4bit.h
  #  components.h
  #  coplanar.h
  #  coupler.h
  #  cpwgap.h
  #  cpwopen.h
  #  cpwshort.h
  #  cpwstep.h
  #  ctline.h
  #  d_flipflop.h
  #  dcblock.h
  #  dcfeed.h
  #  dff_SR.h
  #  diac.h
  #  digi_source.h
  #  DLS_1ton.h
  #  DLS_nto1.h
  #  dmux2to4.h
  #  dmux3to8.h
  #  dmux4to16.h
  #  ecvs.h
  #  EKV26MOS.h
  #  etr_sim.h
  #  fa1b.h
  #  fa2b.h
  #  gatedDlatch.h
  #  greytobinary4bit.h
  #  gyrator.h
  #  ha1b.h
  #  hpribin4bit.h
  #  hybrid.h
  #  ifile.h
  #  isolator.h
  #  jk_flipflop.h
  #  jkff_SR.h
  #  log_amp.h
  #  logic_0.h
  #  logic_1.h
  #  logical_and.h
  #  logical_buf.h
  #  logical_inv.h
  #  logical_nand.h
  #  logical_nor.h
  #  logical_or.h
  #  logical_xnor.h
  #  logical_xor.h
  #  MESFET.h
  #  mod_amp.h
  #  mscorner.h
  #  mscoupled.h
  #  mscross.h
  #  msgap.h
  #  mslange.h
  #  msline.h
  #  msmbend.h
  #  msopen.h
  #  msrstub.h
  #  msstep.h
  #  mstee.h
  #  msvia.h
  #  mutual.h
  #  mutual2.h
  #  mux2to1.h
  #  mux4to1.h
  #  mux8to1.h
  #  nigbt.h
  #  noise_ii.h
  #  noise_iv.h
  #  noise_vv.h
  #  opt_sim.h
  #  pad2bit.h
  #  pad3bit.h
  #  pad4bit.h
  #  phaseshifter.h
  #  photodiode.h
  #  phototransistor.h
  #  pm_modulator.h
  #  potentiometer.h
  #  rectline.h
  #  rfedd.h
  #  rfedd2p.h
  #  rlcg.h
  #  rs_flipflop.h
  #  source_ac.h
  #  sp_sim.h
  #  sparamfile.h
  #  substrate.h
  #  switch.h
  #  symtrafo.h
  #  tff_SR.h
  #  thyristor.h
  #  tline_4port.h
  #  tline.h
  #  transformer.h
  #  triac.h
  #  tunneldiode.h
  #  twistedpair.h
  #vacomponent.h
  #  vafile.h
  #  vcresistor.h
  #  verilogfile.h
  #  vfile.h
  #  vhdlfile.h
  #  volt_noise.h

  # SPICE devices

  #  bsim3v34nMOS.h
  #  bsim3v34pMOS.h
  #  bsim4v30nMOS.h
  #  bsim4v30pMOS.h
  #  hic0_full.h
  #  hic2_full.h
  #  hicumL0V1p2.h
  #  hicumL0V1p2g.h
  #  hicumL0V1p3.h
  #  hicumL2V2p1.h
  #  hicumL2V2p23.h
  #  hicumL2V2p24.h
  #  hicumL2V2p31n.h
  #  HBT_X.h
  )

SET(COMPONENTS_MOC_HDRS
  componentdialog.h
  spicedialog.h
  optimizedialog.h
  spicefile.h
  )

qt6_wrap_cpp(COMPONENTS_MOC_SRCS ${COMPONENTS_MOC_HDRS})

ADD_LIBRARY(components ${COMPONENTS_HDRS} ${COMPONENTS_SRCS} ${COMPONENTS_MOC_SRCS} )
