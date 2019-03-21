function OnStart()
{
  lay = app.CreateLayout( "Linear", "VCenter,FillXY" );

  txt = app.CreateText( "", 0.8, 0.3 );
  lay.AddChild( txt );
  app.AddLayout( lay );

  sns = app.CreateSensor( "Light" );
  sns.SetOnChange( sns_OnChange );
  sns.Start();

}

function sns_OnChange( lux )
{
  txt.SetText( "level = " + lux + " lux" );
}
