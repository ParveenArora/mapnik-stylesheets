<Style name="symbols">
     <Rule>
      &maxscale_zoom16;
      <Filter>[aeroway]='helipad'</Filter>
      <PointSymbolizer file="&symbols;/helipad.p.16.png" />
      <TextSymbolizer name="name" fontset_name="bold-fonts" size="8" fill="#6692da" dy="-10" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
      &maxscale_zoom9;
      &minscale_zoom10;
      <Filter>[aeroway]='airport'</Filter>
      <PointSymbolizer file="&symbols;/airport.p.16.png" />
      <TextSymbolizer name="name" fontset_name="bold-fonts" size="8" fill="#6692da" dy="-12" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
      &maxscale_zoom11;
      &minscale_zoom12;
      <Filter>[aeroway]='airport'</Filter>
      <TextSymbolizer name="name" fontset_name="bold-fonts" size="9" fill="#6692da" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
      &maxscale_zoom10;
      &minscale_zoom10;
      <Filter>[aeroway]='aerodrome'</Filter>
      <PointSymbolizer file="&symbols;/aerodrome.p.16.png" />
      <TextSymbolizer name="name" fontset_name="oblique-fonts" size="8" fill="#6692da" dy="-12" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
      &maxscale_zoom11;
      &minscale_zoom12;
      <Filter>[aeroway]='aerodrome'</Filter>
      <TextSymbolizer name="name" fontset_name="oblique-fonts" size="8" fill="#6692da" halo_radius="1" wrap_width="0"/>
    </Rule>
    <Rule>
      &maxscale_zoom14;
      &minscale_zoom15;
      <Filter>[railway]='level_crossing'</Filter>
      <PointSymbolizer file="&symbols;/level_crossing.png" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <Filter>[railway]='level_crossing'</Filter>
      <PointSymbolizer file="&symbols;/level_crossing2.png" />
    </Rule>
    <Rule>
      &maxscale_zoom15;
      <Filter>[man_made]='lighthouse'</Filter>
      <PointSymbolizer file="&symbols;/lighthouse.p.20.png" />
    </Rule>
    <Rule>
      &maxscale_zoom11;
      <Filter>[natural]='peak'</Filter>
      <PointSymbolizer file="&symbols;/peak.png" />
    </Rule>
    <Rule>
      &maxscale_zoom11;
      <Filter>[natural]='volcano'</Filter>
      <PointSymbolizer file="&symbols;/volcano.png" />
    </Rule>
    <Rule>
      &maxscale_zoom15;
      <Filter>[natural]='cave_entrance'</Filter>
      <PointSymbolizer file="&symbols;/poi_cave.p.16.png" />
    </Rule>
    <Rule>
      &maxscale_zoom14;
      <Filter>[natural]='spring'</Filter>
      <PointSymbolizer file="&symbols;/spring.png" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      &minscale_zoom16;
      <Filter>[natural]='tree'</Filter>
      <PointSymbolizer file="&symbols;/tree.png" />
    </Rule>
    <Rule>
      &maxscale_zoom17;
      <Filter>[natural]='tree'</Filter>
      <PointSymbolizer file="&symbols;/tree2.png" />
    </Rule>
    <Rule>
      &maxscale_zoom15;
      <Filter>[man_made]='power_wind' or ([power]='generator' and [power_source] = 'wind')</Filter>
      <PointSymbolizer file="&symbols;/power_wind.png" />
    </Rule>
    <Rule>
      &maxscale_zoom16;
      <Filter>[man_made]='windmill'</Filter>
      <PointSymbolizer file="&symbols;/windmill.png" />
    </Rule>
    <Rule>
      &maxscale_zoom17;
      <Filter>[man_made]='mast'</Filter>
      <PointSymbolizer file="&symbols;/communications.p.20.png" />
    </Rule>
    <Rule>
      &maxscale_zoom15;
      <Filter>[highway]='mini_roundabout'</Filter>
      <PointSymbolizer file="&symbols;/mini_round.png" allow_overlap="false"/>
    </Rule>
    <Rule>
      &maxscale_zoom15;
      <Filter>[highway]='gate' or [barrier]='gate'</Filter>
      <PointSymbolizer file="&symbols;/gate2.png" allow_overlap="false"/>
    </Rule>
    <Rule> 
 	&maxscale_zoom16; 
 	<Filter>[barrier]='lift_gate'</Filter> 
 	<PointSymbolizer file="&symbols;/liftgate.png" allow_overlap="false"/> 
    </Rule> 
    <Rule>
      &maxscale_zoom16;
      <Filter>[barrier]='bollard' or [barrier]='block'</Filter>
      <PointSymbolizer file="&symbols;/bollard.png" allow_overlap="false"/>
    </Rule>
</Style>

<Layer name="amenity-symbols" status="on" srs="&osm2pgsql_projection;">
    <StyleName>symbols</StyleName>
    <Datasource>
      <Parameter name="table">
      (select *
      from &prefix;_point
      where aeroway in ('airport','aerodrome','helipad')
         or barrier in ('bollard','gate','lift_gate','block')
         or highway in ('mini_roundabout','gate')
         or man_made in ('lighthouse','power_wind','windmill','mast')
         or (power='generator' and power_source='wind')
         or "natural" in ('peak','volcano','spring','tree','cave_entrance')
         or railway='level_crossing'
      ) as symbols</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
<Layer name="amenity-symbols-poly" status="on" srs="&osm2pgsql_projection;">
    <StyleName>symbols</StyleName>
    <Datasource>
      <Parameter name="table">
      (select *
      from &prefix;_polygon
      where aeroway in ('airport','aerodrome','helipad')
         or barrier in ('bollard','gate','lift_gate','block')
         or highway in ('mini_roundabout','gate')
         or man_made in ('lighthouse','power_wind','windmill','mast')
         or (power='generator' and power_source='wind')
         or "natural" in ('peak','volcano','spring','tree')
         or railway='level_crossing'
      ) as symbols</Parameter>
      &datasource-settings;
    </Datasource>
</Layer>
