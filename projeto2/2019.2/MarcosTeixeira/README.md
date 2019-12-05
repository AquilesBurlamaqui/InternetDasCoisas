# Projeto 02: Plotagem de gráfico com os dados do acelerômetro de smartphone Android no ThingSpeak

### Conhecimentos necessários

- Javascript

### Ferramentas 

- Sublime Text 3
- DroidScript 
- ThingSpeak

### Materiais 
- Smartphone Moto X4

‘‘‘
function OnStart()
{
  lay = app.CreateLayout( "Linear", "VCenter,FillXY" );
 
  txt = app.CreateText( "", 0.8, 0.3, "Multiline" );
  lay.AddChild( txt );
  app.AddLayout( lay );
 
  sns = app.CreateSensor( "Accelerometer" );
  sns.SetOnChange( sns_OnChange );
  sns.Start();
 
}
 
function sns_OnChange( x, y, z, time )
{
  txt.SetText( "x="+x + "\n y="+y + "\n z="+z );
}
’’’
