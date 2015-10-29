<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="7.4.0">
<drawing>
<settings>
<setting alwaysvectorfont="no"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="2" name="Route2" color="1" fill="3" visible="no" active="no"/>
<layer number="3" name="Route3" color="4" fill="3" visible="no" active="no"/>
<layer number="4" name="Route4" color="1" fill="4" visible="no" active="no"/>
<layer number="5" name="Route5" color="4" fill="4" visible="no" active="no"/>
<layer number="6" name="Route6" color="1" fill="8" visible="no" active="no"/>
<layer number="7" name="Route7" color="4" fill="8" visible="no" active="no"/>
<layer number="8" name="Route8" color="1" fill="2" visible="no" active="no"/>
<layer number="9" name="Route9" color="4" fill="2" visible="no" active="no"/>
<layer number="10" name="Route10" color="1" fill="7" visible="no" active="no"/>
<layer number="11" name="Route11" color="4" fill="7" visible="no" active="no"/>
<layer number="12" name="Route12" color="1" fill="5" visible="no" active="no"/>
<layer number="13" name="Route13" color="4" fill="5" visible="no" active="no"/>
<layer number="14" name="Route14" color="1" fill="6" visible="no" active="no"/>
<layer number="15" name="Route15" color="4" fill="6" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="con-ptr500">
<description>&lt;b&gt;PTR Connectors&lt;/b&gt;&lt;p&gt;
Aug. 2004 / PTR Meßtechnik:&lt;br&gt;
Die Bezeichnung der Serie AK505 wurde geändert.&lt;br&gt;
Es handelt sich hierbei um AK500 in horizontaler Ausführung.&lt;p&gt;
&lt;TABLE BORDER=0 CELLSPACING=1 CELLPADDING=2&gt;
  &lt;TR&gt;
    &lt;TD ALIGN=LEFT&gt;
      &lt;FONT SIZE=4 FACE=ARIAL&gt;&lt;B&gt;Alte Bezeichnung&lt;/B&gt;&lt;/FONT&gt;
    &lt;/TD&gt;
    &lt;TD ALIGN=LEFT&gt;
      &lt;FONT SIZE=4 FACE=ARIAL&gt;&lt;B&gt;Neue Bezeichnung&lt;/B&gt;&lt;/FONT&gt;
    &lt;/TD&gt;
  &lt;/TR&gt;
  &lt;TR&gt;
    &lt;TD ALIGN=LEFT&gt;
      &lt;B&gt;
      &lt;FONT SIZE=3 FACE=ARIAL color="#FF0000"&gt;AK505/2,grau&lt;/FONT&gt;
      &lt;/B&gt;
    &lt;/TD&gt;
    &lt;TD ALIGN=LEFT&gt;
      &lt;B&gt;
      &lt;FONT SIZE=3 FACE=ARIAL color="#0000FF"&gt;AK500/2-5.0-H-GRAU&lt;/FONT&gt;
      &lt;/B&gt;
    &lt;/TD&gt;
  &lt;/TR&gt;
  &lt;TR&gt;
    &lt;TD ALIGN=LEFT&gt;
      &lt;B&gt;
      &lt;FONT SIZE=3 FACE=ARIAL color="#FF0000"&gt;AK505/2DS,grau&lt;/FONT&gt;
      &lt;/B&gt;
    &lt;/TD&gt;
    &lt;TD ALIGN=LEFT&gt;
      &lt;B&gt;
      &lt;FONT SIZE=3 FACE=ARIAL color="#0000FF"&gt;AK500/2DS-5.0-H-GRAU&lt;/FONT&gt;
      &lt;/B&gt;
    &lt;/TD&gt;
  &lt;/TR&gt;
  &lt;TR&gt;
    &lt;TD ALIGN=LEFT&gt;
      &lt;B&gt;
      &lt;FONT SIZE=3 FACE=ARIAL color="#FF0000"&gt;AKZ505/2,grau&lt;/FONT&gt;
      &lt;/B&gt;
    &lt;/TD&gt;
    &lt;TD ALIGN=LEFT&gt;
      &lt;B&gt;
      &lt;FONT SIZE=3 FACE=ARIAL color="#0000FF"&gt;AKZ500/2-5.08-H-GRAU&lt;/FONT&gt;
      &lt;/B&gt;
    &lt;/TD&gt;
  &lt;/TABLE&gt;

&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="AK500/2-H">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
Aug. 2004 / PTR Meßtechnik:&lt;br&gt;
Die Bezeichnung der Serie AK505 wurde geändert.&lt;br&gt;
Es handelt sich hierbei um AK500 in horizontaler Ausführung.</description>
<wire x1="-5.08" y1="-7.239" x2="-5.08" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="5.08" y1="2.794" x2="-5.08" y2="2.794" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-7.239" x2="-4.318" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="5.08" y1="2.794" x2="5.08" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-3.429" x2="5.08" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="-5.08" y1="-3.429" x2="-5.08" y2="2.794" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-3.429" x2="5.08" y2="-3.81" width="0.1524" layer="21"/>
<wire x1="5.461" y1="2.794" x2="5.461" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="5.461" y1="-3.429" x2="5.08" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="5.461" y1="2.794" x2="5.08" y2="2.794" width="0.1524" layer="21"/>
<wire x1="-0.4826" y1="2.159" x2="-0.4826" y2="-2.794" width="0.1524" layer="21"/>
<wire x1="-4.5466" y1="-2.794" x2="-0.4826" y2="-2.794" width="0.1524" layer="21"/>
<wire x1="-4.5466" y1="-2.794" x2="-4.5466" y2="2.159" width="0.1524" layer="21"/>
<wire x1="-0.4826" y1="2.159" x2="-4.5466" y2="2.159" width="0.1524" layer="21"/>
<wire x1="0.4826" y1="2.159" x2="0.4826" y2="-2.794" width="0.1524" layer="21"/>
<wire x1="0.4826" y1="-2.794" x2="4.5466" y2="-2.794" width="0.1524" layer="21"/>
<wire x1="4.5466" y1="-2.794" x2="4.5466" y2="2.159" width="0.1524" layer="21"/>
<wire x1="4.5466" y1="2.159" x2="0.4826" y2="2.159" width="0.1524" layer="21"/>
<wire x1="4.8006" y1="-3.048" x2="0.2286" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="4.8006" y1="-3.048" x2="4.8006" y2="2.413" width="0.0508" layer="21"/>
<wire x1="0.2286" y1="2.413" x2="4.8006" y2="2.413" width="0.0508" layer="21"/>
<wire x1="0.2286" y1="2.413" x2="0.2286" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="-0.2286" y1="2.413" x2="-0.2286" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="-4.8006" y1="2.413" x2="-0.2286" y2="2.413" width="0.0508" layer="21"/>
<wire x1="-4.8006" y1="2.413" x2="-4.8006" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="-0.2286" y1="-3.048" x2="-4.8006" y2="-3.048" width="0.0508" layer="21"/>
<wire x1="-4.5466" y1="0" x2="-0.4826" y2="0" width="0.1524" layer="21" curve="-180"/>
<wire x1="-4.5466" y1="-2.413" x2="-4.2926" y2="-2.667" width="0.1524" layer="21" curve="90"/>
<wire x1="-0.7366" y1="-2.667" x2="-0.4826" y2="-2.413" width="0.1524" layer="21" curve="90"/>
<wire x1="-0.7366" y1="-2.667" x2="-4.2926" y2="-2.667" width="0.1524" layer="21"/>
<wire x1="-1.3716" y1="-2.413" x2="-1.1176" y2="-2.667" width="0.1524" layer="21" curve="90"/>
<wire x1="-3.9116" y1="-2.667" x2="-3.6576" y2="-2.413" width="0.1524" layer="21" curve="90"/>
<wire x1="-3.6576" y1="-0.127" x2="-3.6576" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-0.127" x2="-1.3716" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="-1.3716" y1="-0.127" x2="-1.3716" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-0.762" x2="-1.3716" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="-3.6576" y1="-0.762" x2="-3.6576" y2="-2.413" width="0.1524" layer="21"/>
<wire x1="-1.3716" y1="-0.762" x2="-1.3716" y2="-2.413" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-3.81" x2="-5.08" y2="-3.81" width="0.0508" layer="21"/>
<wire x1="-5.08" y1="-3.81" x2="-5.08" y2="-3.429" width="0.1524" layer="21"/>
<wire x1="5.08" y1="-3.81" x2="5.08" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="0.4826" y1="0" x2="4.5466" y2="0" width="0.1524" layer="21" curve="-180"/>
<wire x1="1.3716" y1="-0.127" x2="3.6576" y2="-0.127" width="0.1524" layer="51"/>
<wire x1="1.3716" y1="-0.127" x2="1.3716" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.3716" y1="-0.762" x2="3.6576" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.3716" y1="-0.762" x2="1.3716" y2="-2.413" width="0.1524" layer="21"/>
<wire x1="3.6576" y1="-0.762" x2="3.6576" y2="-2.413" width="0.1524" layer="21"/>
<wire x1="3.6576" y1="-0.127" x2="3.6576" y2="-0.762" width="0.1524" layer="51"/>
<wire x1="1.1176" y1="-2.667" x2="1.3716" y2="-2.413" width="0.1524" layer="21" curve="90"/>
<wire x1="3.6576" y1="-2.413" x2="3.9116" y2="-2.667" width="0.1524" layer="21" curve="90"/>
<wire x1="4.2926" y1="-2.667" x2="0.7366" y2="-2.667" width="0.1524" layer="21"/>
<wire x1="4.2926" y1="-2.667" x2="4.5466" y2="-2.413" width="0.1524" layer="21" curve="90"/>
<wire x1="0.4826" y1="-2.413" x2="0.7366" y2="-2.667" width="0.1524" layer="21" curve="90"/>
<wire x1="-0.762" y1="-7.366" x2="-0.762" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="-0.762" y1="-7.239" x2="0.762" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="-7.366" x2="-4.318" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="-7.239" x2="-2.794" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="-4.318" y1="-7.366" x2="-2.794" y2="-7.366" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-7.239" x2="-2.794" y2="-7.366" width="0.1524" layer="21"/>
<wire x1="-2.794" y1="-7.239" x2="-2.286" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-7.239" x2="-0.762" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-7.366" x2="-2.286" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="-2.286" y1="-7.366" x2="-0.762" y2="-7.366" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-7.239" x2="2.286" y2="-7.366" width="0.1524" layer="21"/>
<wire x1="2.286" y1="-7.239" x2="2.794" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="0.762" y1="-7.366" x2="2.286" y2="-7.366" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-7.366" x2="2.794" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-7.239" x2="4.318" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="2.794" y1="-7.366" x2="4.318" y2="-7.366" width="0.1524" layer="21"/>
<wire x1="4.318" y1="-7.366" x2="4.318" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="4.318" y1="-7.239" x2="5.08" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="0.762" y1="-7.366" x2="0.762" y2="-7.239" width="0.1524" layer="21"/>
<wire x1="0.762" y1="-7.239" x2="2.286" y2="-7.239" width="0.1524" layer="21"/>
<circle x="-2.5146" y="0" radius="1.397" width="0.1524" layer="51"/>
<circle x="2.5146" y="0" radius="1.397" width="0.1524" layer="51"/>
<pad name="1" x="-2.5146" y="0" drill="1.3208" shape="long" rot="R90"/>
<pad name="2" x="2.5146" y="0" drill="1.3208" shape="long" rot="R90"/>
<text x="-5.08" y="3.556" size="1.778" layer="25" ratio="10">&gt;NAME</text>
<text x="-5.08" y="-9.525" size="1.778" layer="27" ratio="10">&gt;VALUE</text>
<text x="-3.175" y="-5.715" size="1.27" layer="21" ratio="10">1</text>
<text x="1.905" y="-5.715" size="1.27" layer="21" ratio="10">2</text>
<rectangle x1="-3.6576" y1="-1.524" x2="-1.3716" y2="-0.762" layer="51"/>
<rectangle x1="1.3716" y1="-1.524" x2="3.6576" y2="-0.762" layer="51"/>
<rectangle x1="-3.6576" y1="-2.667" x2="-1.3716" y2="-1.524" layer="21"/>
<rectangle x1="1.3716" y1="-2.667" x2="3.6576" y2="-1.524" layer="21"/>
</package>
</packages>
<symbols>
<symbol name="KL">
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<text x="-1.27" y="0.889" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<pin name="KL" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
<symbol name="KLV">
<circle x="1.27" y="0" radius="1.27" width="0.254" layer="94"/>
<text x="-1.27" y="0.889" size="1.778" layer="95" rot="R180">&gt;NAME</text>
<text x="-3.81" y="-3.683" size="1.778" layer="96">&gt;VALUE</text>
<pin name="KL" x="5.08" y="0" visible="off" length="short" direction="pas" rot="R180"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="AK500/2-H" prefix="X" uservalue="yes">
<description>&lt;b&gt;CONNECTOR&lt;/b&gt;&lt;p&gt;
Aug. 2004 / PTR Meßtechnik:&lt;br&gt;
Die Bezeichnung der Serie AK505 wurde geändert.&lt;br&gt;
Es handelt sich hierbei um AK500 in horizontaler Ausführung.</description>
<gates>
<gate name="-1" symbol="KL" x="0" y="5.08" addlevel="always"/>
<gate name="-2" symbol="KLV" x="0" y="0" addlevel="always"/>
</gates>
<devices>
<device name="" package="AK500/2-H">
<connects>
<connect gate="-1" pin="KL" pad="1"/>
<connect gate="-2" pin="KL" pad="2"/>
</connects>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="Minero">
<packages>
<package name="CHB">
<wire x1="0" y1="0" x2="28.956" y2="0" width="0.127" layer="21"/>
<wire x1="28.956" y1="0" x2="57.912" y2="0" width="0.127" layer="21"/>
<wire x1="57.912" y1="0" x2="57.912" y2="30.48" width="0.127" layer="21"/>
<wire x1="57.912" y1="30.48" x2="57.912" y2="60.96" width="0.127" layer="21"/>
<wire x1="57.912" y1="60.96" x2="28.956" y2="60.96" width="0.127" layer="21"/>
<wire x1="28.956" y1="60.96" x2="0" y2="60.96" width="0.127" layer="21"/>
<wire x1="0" y1="60.96" x2="0" y2="30.48" width="0.127" layer="21"/>
<wire x1="0" y1="30.48" x2="0" y2="0" width="0.127" layer="21"/>
<wire x1="0" y1="30.48" x2="57.912" y2="30.48" width="0.127" layer="21" style="dashdot"/>
<wire x1="28.956" y1="0" x2="28.956" y2="60.96" width="0.127" layer="21" style="dashdot"/>
<hole x="4.826" y="5.08" drill="3.2"/>
<hole x="4.826" y="55.88" drill="3.2"/>
<hole x="53.086" y="55.88" drill="3.2"/>
<hole x="53.086" y="5.08" drill="3.2"/>
<pad name="CASE" x="4.826" y="38.1" drill="1.1" diameter="1.778" shape="long"/>
<pad name="-VIN" x="4.826" y="48.26" drill="1.1" diameter="1.778" shape="long"/>
<pad name="ON/OFF" x="4.826" y="22.86" drill="1.1" diameter="1.778" shape="long"/>
<pad name="+VIN" x="4.826" y="12.7" drill="1.1" diameter="1.778" shape="long"/>
<pad name="+VOUT" x="53.086" y="12.7" drill="1.1" diameter="1.778" shape="long"/>
<pad name="+SENSE" x="53.086" y="22.86" drill="1.1" diameter="1.778" shape="long"/>
<pad name="TRIM" x="53.086" y="30.48" drill="1.1" diameter="1.778" shape="long"/>
<pad name="-SENSE" x="53.086" y="38.1" drill="1.1" diameter="1.778" shape="long"/>
<pad name="-VOUT" x="53.086" y="48.26" drill="1.1" diameter="1.778" shape="long"/>
<text x="0" y="-3.81" size="2.54" layer="25">&gt;NAME</text>
<text x="0" y="-8.89" size="2.54" layer="27">&gt;VALUE</text>
</package>
</packages>
<symbols>
<symbol name="CHB">
<pin name="+VIN" x="-17.78" y="-10.16" length="middle" direction="in"/>
<pin name="ON/OFF" x="-17.78" y="-5.08" length="middle"/>
<pin name="CASE" x="-17.78" y="5.08" length="middle"/>
<pin name="-VIN" x="-17.78" y="10.16" length="middle" direction="in"/>
<pin name="-VOUT" x="17.78" y="10.16" length="middle" direction="out" rot="R180"/>
<pin name="-SENSE" x="17.78" y="5.08" length="middle" rot="R180"/>
<pin name="TRIM" x="17.78" y="0" length="middle" rot="R180"/>
<pin name="+SENSE" x="17.78" y="-5.08" length="middle" rot="R180"/>
<pin name="+VOUT" x="17.78" y="-10.16" length="middle" direction="out" rot="R180"/>
<wire x1="-12.7" y1="12.7" x2="12.7" y2="12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="12.7" x2="12.7" y2="-12.7" width="0.254" layer="94"/>
<wire x1="12.7" y1="-12.7" x2="-12.7" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-12.7" x2="-12.7" y2="12.7" width="0.254" layer="94"/>
<text x="-12.7" y="15.24" size="1.27" layer="95">&gt;Name</text>
<text x="-12.7" y="12.7" size="1.27" layer="96">&gt;Value</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="CHB100W">
<description>CHB100W DC-DC Converter</description>
<gates>
<gate name="G$1" symbol="CHB" x="0" y="0"/>
</gates>
<devices>
<device name="" package="CHB">
<connects>
<connect gate="G$1" pin="+SENSE" pad="+SENSE"/>
<connect gate="G$1" pin="+VIN" pad="+VIN"/>
<connect gate="G$1" pin="+VOUT" pad="+VOUT"/>
<connect gate="G$1" pin="-SENSE" pad="-SENSE"/>
<connect gate="G$1" pin="-VIN" pad="-VIN"/>
<connect gate="G$1" pin="-VOUT" pad="-VOUT"/>
<connect gate="G$1" pin="CASE" pad="CASE"/>
<connect gate="G$1" pin="ON/OFF" pad="ON/OFF"/>
<connect gate="G$1" pin="TRIM" pad="TRIM"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="FTE1" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="FTE2" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="FTE3" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="FTE4" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="FTE5" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="FTE6" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="SALIDA48_1" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="48S24" library="Minero" deviceset="CHB100W" device=""/>
<part name="48S12" library="Minero" deviceset="CHB100W" device=""/>
<part name="48S05" library="Minero" deviceset="CHB100W" device=""/>
<part name="SALIDA24" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="SALIDA12" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="SALIDA05" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="SALIDA48_2" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="SALIDA48_3" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="SALIDA48_4" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="SALIDA48_5" library="con-ptr500" deviceset="AK500/2-H" device=""/>
<part name="SALIDA48_6" library="con-ptr500" deviceset="AK500/2-H" device=""/>
</parts>
<sheets>
<sheet>
<plain>
</plain>
<instances>
<instance part="FTE1" gate="-1" x="-7.62" y="93.98"/>
<instance part="FTE1" gate="-2" x="-7.62" y="88.9"/>
<instance part="FTE2" gate="-1" x="-7.62" y="83.82"/>
<instance part="FTE2" gate="-2" x="-7.62" y="78.74"/>
<instance part="FTE3" gate="-1" x="-7.62" y="73.66"/>
<instance part="FTE3" gate="-2" x="-7.62" y="68.58"/>
<instance part="FTE4" gate="-1" x="-7.62" y="63.5"/>
<instance part="FTE4" gate="-2" x="-7.62" y="58.42"/>
<instance part="FTE5" gate="-1" x="-7.62" y="53.34"/>
<instance part="FTE5" gate="-2" x="-7.62" y="48.26"/>
<instance part="FTE6" gate="-1" x="-7.62" y="43.18"/>
<instance part="FTE6" gate="-2" x="-7.62" y="38.1"/>
<instance part="SALIDA48_1" gate="-1" x="33.02" y="93.98" rot="MR0"/>
<instance part="SALIDA48_1" gate="-2" x="33.02" y="88.9" rot="MR0"/>
<instance part="48S24" gate="G$1" x="83.82" y="88.9"/>
<instance part="48S12" gate="G$1" x="83.82" y="55.88"/>
<instance part="48S05" gate="G$1" x="83.82" y="22.86"/>
<instance part="SALIDA24" gate="-1" x="119.38" y="78.74" rot="MR0"/>
<instance part="SALIDA24" gate="-2" x="119.38" y="99.06" rot="MR0"/>
<instance part="SALIDA12" gate="-1" x="119.38" y="45.72" rot="MR0"/>
<instance part="SALIDA12" gate="-2" x="119.38" y="66.04" rot="MR0"/>
<instance part="SALIDA05" gate="-1" x="119.38" y="12.7" rot="MR0"/>
<instance part="SALIDA05" gate="-2" x="119.38" y="33.02" rot="MR0"/>
<instance part="SALIDA48_2" gate="-1" x="33.02" y="83.82" rot="MR0"/>
<instance part="SALIDA48_2" gate="-2" x="33.02" y="78.74" rot="MR0"/>
<instance part="SALIDA48_3" gate="-1" x="33.02" y="73.66" rot="MR0"/>
<instance part="SALIDA48_3" gate="-2" x="33.02" y="68.58" rot="MR0"/>
<instance part="SALIDA48_4" gate="-1" x="33.02" y="63.5" rot="MR0"/>
<instance part="SALIDA48_4" gate="-2" x="33.02" y="58.42" rot="MR0"/>
<instance part="SALIDA48_5" gate="-1" x="33.02" y="53.34" rot="MR0"/>
<instance part="SALIDA48_5" gate="-2" x="33.02" y="48.26" rot="MR0"/>
<instance part="SALIDA48_6" gate="-1" x="33.02" y="43.18" rot="MR0"/>
<instance part="SALIDA48_6" gate="-2" x="33.02" y="38.1" rot="MR0"/>
</instances>
<busses>
<bus name="VCC">
<segment>
<wire x1="15.24" y1="93.98" x2="15.24" y2="30.48" width="0.762" layer="92"/>
<label x="15.24" y="25.4" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="55.88" y1="73.66" x2="60.96" y2="73.66" width="0.762" layer="92"/>
<label x="48.26" y="73.66" size="1.778" layer="95"/>
</segment>
</bus>
<bus name="GND">
<segment>
<wire x1="20.32" y1="93.98" x2="20.32" y2="30.48" width="0.762" layer="92"/>
<label x="20.32" y="96.52" size="1.778" layer="95"/>
</segment>
<segment>
<wire x1="50.8" y1="35.56" x2="55.88" y2="35.56" width="0.762" layer="92"/>
</segment>
</bus>
</busses>
<nets>
<net name="VCC" class="0">
<segment>
<pinref part="FTE1" gate="-1" pin="KL"/>
<wire x1="15.24" y1="91.44" x2="-2.54" y2="93.98" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="FTE2" gate="-1" pin="KL"/>
<wire x1="-2.54" y1="83.82" x2="15.24" y2="81.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="FTE3" gate="-1" pin="KL"/>
<wire x1="-2.54" y1="73.66" x2="15.24" y2="71.12" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="FTE4" gate="-1" pin="KL"/>
<wire x1="-2.54" y1="63.5" x2="15.24" y2="60.96" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="-2.54" y1="53.34" x2="15.24" y2="50.8" width="0.1524" layer="91"/>
<pinref part="FTE5" gate="-1" pin="KL"/>
</segment>
<segment>
<pinref part="FTE6" gate="-1" pin="KL"/>
<wire x1="-2.54" y1="43.18" x2="15.24" y2="40.64" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="48S24" gate="G$1" pin="+VIN"/>
<wire x1="66.04" y1="78.74" x2="58.42" y2="78.74" width="0.1524" layer="91"/>
<wire x1="58.42" y1="78.74" x2="58.42" y2="73.66" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="48S12" gate="G$1" pin="+VIN"/>
<wire x1="66.04" y1="45.72" x2="58.42" y2="45.72" width="0.1524" layer="91"/>
<wire x1="58.42" y1="45.72" x2="58.42" y2="73.66" width="0.1524" layer="91"/>
<pinref part="48S05" gate="G$1" pin="+VIN"/>
<wire x1="66.04" y1="12.7" x2="58.42" y2="12.7" width="0.1524" layer="91"/>
<wire x1="58.42" y1="12.7" x2="58.42" y2="45.72" width="0.1524" layer="91"/>
<junction x="58.42" y="45.72"/>
</segment>
<segment>
<pinref part="SALIDA48_1" gate="-1" pin="KL"/>
<wire x1="27.94" y1="93.98" x2="15.24" y2="91.44" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_2" gate="-1" pin="KL"/>
<wire x1="27.94" y1="83.82" x2="15.24" y2="81.28" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_3" gate="-1" pin="KL"/>
<wire x1="27.94" y1="73.66" x2="15.24" y2="71.12" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_4" gate="-1" pin="KL"/>
<wire x1="27.94" y1="63.5" x2="15.24" y2="60.96" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_5" gate="-1" pin="KL"/>
<wire x1="27.94" y1="53.34" x2="15.24" y2="50.8" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_6" gate="-1" pin="KL"/>
<wire x1="27.94" y1="43.18" x2="15.24" y2="40.64" width="0.1524" layer="91"/>
</segment>
</net>
<net name="GND" class="0">
<segment>
<pinref part="FTE1" gate="-2" pin="KL"/>
<wire x1="20.32" y1="86.36" x2="-2.54" y2="88.9" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="FTE2" gate="-2" pin="KL"/>
<wire x1="20.32" y1="76.2" x2="-2.54" y2="78.74" width="0.1524" layer="91"/>
</segment>
<segment>
<wire x1="20.32" y1="66.04" x2="-2.54" y2="68.58" width="0.1524" layer="91"/>
<pinref part="FTE3" gate="-2" pin="KL"/>
</segment>
<segment>
<pinref part="FTE4" gate="-2" pin="KL"/>
<wire x1="20.32" y1="55.88" x2="-2.54" y2="58.42" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="FTE5" gate="-2" pin="KL"/>
<wire x1="20.32" y1="45.72" x2="-2.54" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="FTE6" gate="-2" pin="KL"/>
<wire x1="20.32" y1="35.56" x2="-2.54" y2="38.1" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="48S12" gate="G$1" pin="-VIN"/>
<wire x1="53.34" y1="35.56" x2="53.34" y2="66.04" width="0.1524" layer="91"/>
<wire x1="53.34" y1="66.04" x2="66.04" y2="66.04" width="0.1524" layer="91"/>
<pinref part="48S24" gate="G$1" pin="-VIN"/>
<wire x1="66.04" y1="99.06" x2="53.34" y2="99.06" width="0.1524" layer="91"/>
<wire x1="53.34" y1="99.06" x2="53.34" y2="66.04" width="0.1524" layer="91"/>
<junction x="53.34" y="66.04"/>
</segment>
<segment>
<pinref part="48S05" gate="G$1" pin="-VIN"/>
<wire x1="66.04" y1="33.02" x2="53.34" y2="33.02" width="0.1524" layer="91"/>
<wire x1="53.34" y1="33.02" x2="53.34" y2="35.56" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_1" gate="-2" pin="KL"/>
<wire x1="27.94" y1="88.9" x2="20.32" y2="86.36" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_2" gate="-2" pin="KL"/>
<wire x1="27.94" y1="78.74" x2="20.32" y2="76.2" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_3" gate="-2" pin="KL"/>
<wire x1="27.94" y1="68.58" x2="20.32" y2="66.04" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_4" gate="-2" pin="KL"/>
<wire x1="27.94" y1="58.42" x2="20.32" y2="55.88" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_5" gate="-2" pin="KL"/>
<wire x1="27.94" y1="48.26" x2="20.32" y2="45.72" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="SALIDA48_6" gate="-2" pin="KL"/>
<wire x1="27.94" y1="38.1" x2="20.32" y2="35.56" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$1" class="0">
<segment>
<pinref part="48S05" gate="G$1" pin="+VOUT"/>
<pinref part="SALIDA05" gate="-1" pin="KL"/>
<wire x1="101.6" y1="12.7" x2="114.3" y2="12.7" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$2" class="0">
<segment>
<pinref part="SALIDA05" gate="-2" pin="KL"/>
<pinref part="48S05" gate="G$1" pin="-VOUT"/>
<wire x1="114.3" y1="33.02" x2="101.6" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$3" class="0">
<segment>
<pinref part="SALIDA12" gate="-1" pin="KL"/>
<pinref part="48S12" gate="G$1" pin="+VOUT"/>
<wire x1="114.3" y1="45.72" x2="101.6" y2="45.72" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$4" class="0">
<segment>
<pinref part="48S12" gate="G$1" pin="-VOUT"/>
<pinref part="SALIDA12" gate="-2" pin="KL"/>
<wire x1="101.6" y1="66.04" x2="114.3" y2="66.04" width="0.1524" layer="91"/>
</segment>
</net>
<net name="N$5" class="0">
<segment>
<pinref part="SALIDA24" gate="-1" pin="KL"/>
<wire x1="114.3" y1="78.74" x2="101.6" y2="78.74" width="0.1524" layer="91"/>
<pinref part="48S24" gate="G$1" pin="+VOUT"/>
</segment>
</net>
<net name="N$6" class="0">
<segment>
<pinref part="SALIDA24" gate="-2" pin="KL"/>
<pinref part="48S24" gate="G$1" pin="-VOUT"/>
<wire x1="114.3" y1="99.06" x2="101.6" y2="99.06" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
</eagle>