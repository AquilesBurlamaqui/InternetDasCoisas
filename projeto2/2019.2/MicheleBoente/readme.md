<h1>Projeto 2 - Atualiza&ccedil;&atilde;o do gr&aacute;fico ThingSpeak via sensor do celular</h1>
<h3><a id="user-content-passo-1---instalar-o-app-droidscript-no-celular-android" class="anchor" href="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2#passo-1---instalar-o-app-droidscript-no-celular-android" aria-hidden="true"></a>Passo 1 - Instalar o app DroidScript no celular (android);</h3>
<p>Somente para android:&nbsp;<a href="https://play.google.com/store/apps/details?id=com.smartphoneremote.androidscriptfree&amp;hl=pt" rel="nofollow">https://play.google.com/store/apps/details?id=com.smartphoneremote.androidscriptfree&amp;hl=pt</a></p>
<h3><a id="user-content-passo-2---no-droidscript-procurar-nas-refer&ecirc;ncias-e-executar-exemplos-de-c&oacute;digos-com-sensoresex-sensor-de-luz-ou-aceler&ocirc;metro" class="anchor" href="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2#passo-2---no-droidscript-procurar-nas-refer%C3%AAncias-e-executar-exemplos-de-c%C3%B3digos-com-sensoresex-sensor-de-luz-ou-aceler%C3%B4metro" aria-hidden="true"></a>Passo 2 - No DroidScript procurar nas refer&ecirc;ncias e executar exemplos de c&oacute;digos com sensores(ex. Sensor de luz ou Aceler&ocirc;metro)</h3>
<p>O c&oacute;digo abaixo exibe o valor retornado pelo sensor de luz do celular.</p>
<div class="highlight highlight-source-js">
<pre><span class="pl-k">function</span> <span class="pl-en">OnStart</span>()
{
  lay <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateLayout</span>( <span class="pl-s"><span class="pl-pds">"</span>Linear<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">"</span>VCenter,FillXY<span class="pl-pds">"</span></span> );

  txt <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateText</span>( <span class="pl-s"><span class="pl-pds">"</span><span class="pl-pds">"</span></span>, <span class="pl-c1">0.8</span>, <span class="pl-c1">0.3</span> );
  <span class="pl-smi">lay</span>.<span class="pl-en">AddChild</span>( txt );
  <span class="pl-smi">app</span>.<span class="pl-en">AddLayout</span>( lay );

  sns <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateSensor</span>( <span class="pl-s"><span class="pl-pds">"</span>Light<span class="pl-pds">"</span></span> );
  <span class="pl-smi">sns</span>.<span class="pl-en">SetOnChange</span>( sns_OnChange );
  <span class="pl-smi">sns</span>.<span class="pl-en">Start</span>();

}

<span class="pl-k">function</span> <span class="pl-en">sns_OnChange</span>( <span class="pl-smi">lux</span> )
{
  <span class="pl-smi">txt</span>.<span class="pl-en">SetText</span>( <span class="pl-s"><span class="pl-pds">"</span>level = <span class="pl-pds">"</span></span> <span class="pl-k">+</span> lux <span class="pl-k">+</span> <span class="pl-s"><span class="pl-pds">"</span> lux<span class="pl-pds">"</span></span> );
}

</pre>
</div>
<h3><a id="user-content-passo-3---construir-um-c&oacute;digo-no-droidscript-que-exiba-a-cada-10s-a-informa&ccedil;&atilde;o-capturada-do-sensor" class="anchor" href="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2#passo-3---construir-um-c%C3%B3digo-no-droidscript-que-exiba-a-cada-10s-a-informa%C3%A7%C3%A3o-capturada-do-sensor" aria-hidden="true"></a>Passo 3 - Construir um c&oacute;digo no droidscript que exiba a cada 10s a informa&ccedil;&atilde;o capturada do sensor;</h3>
<div class="highlight highlight-source-js">
<pre>luxGlobal <span class="pl-k">=</span> <span class="pl-c1">0</span>;
<span class="pl-k">function</span> <span class="pl-en">setLuxText</span>() {
    <span class="pl-smi">txt</span>.<span class="pl-en">SetText</span>(<span class="pl-s"><span class="pl-pds">"</span> level = <span class="pl-pds">"</span></span> <span class="pl-k">+</span> luxGlobal <span class="pl-k">+</span> <span class="pl-s"><span class="pl-pds">"</span> luxGlobal<span class="pl-pds">"</span></span> <span class="pl-k">+</span>count);
}

<span class="pl-k">function</span> <span class="pl-en">OnStart</span>()
{
  lay <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateLayout</span>( <span class="pl-s"><span class="pl-pds">"</span>Linear<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">"</span>VCenter,FillXY<span class="pl-pds">"</span></span> );

  txt <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateText</span>( <span class="pl-s"><span class="pl-pds">"</span><span class="pl-pds">"</span></span>, <span class="pl-c1">0.8</span>, <span class="pl-c1">0.3</span> );
  <span class="pl-smi">lay</span>.<span class="pl-en">AddChild</span>( txt );
  <span class="pl-smi">app</span>.<span class="pl-en">AddLayout</span>( lay );

  sns <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateSensor</span>( <span class="pl-s"><span class="pl-pds">"</span>Light<span class="pl-pds">"</span></span> );
  <span class="pl-smi">sns</span>.<span class="pl-en">SetOnChange</span>( sns_OnChange );
  <span class="pl-smi">sns</span>.<span class="pl-en">Start</span>();
  <span class="pl-c1">setInterval</span>(<span class="pl-k">function</span>(){
      <span class="pl-smi">txt</span>.<span class="pl-en">SetText</span>(<span class="pl-s"><span class="pl-pds">"</span> level = <span class="pl-pds">"</span></span> <span class="pl-k">+</span> luxGlobal <span class="pl-k">+</span> <span class="pl-s"><span class="pl-pds">"</span> luxGlobal<span class="pl-pds">"</span></span>);
      }, <span class="pl-c1">10000</span>);
  
}

<span class="pl-k">function</span> <span class="pl-en">sns_OnChange</span>( <span class="pl-smi">lux</span> )
{
  <span class="pl-c">//txt.SetText( "level = " + lux + " lux" );</span>
  luxGlobal <span class="pl-k">=</span> lux;
}</pre>
</div>
<h3><a id="user-content-passo-4---enviar-essa-informa&ccedil;&atilde;o-para-o-thingspeak" class="anchor" href="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2#passo-4---enviar-essa-informa%C3%A7%C3%A3o-para-o-thingspeak" aria-hidden="true"></a>Passo 4 - Enviar essa informa&ccedil;&atilde;o para o thingspeak;</h3>
<div class="highlight highlight-source-js">
<pre>luxGlobal <span class="pl-k">=</span> <span class="pl-c1">0</span>;
<span class="pl-c">//Chamada quando a aplicacao inicia</span>
<span class="pl-k">function</span> <span class="pl-en">OnStart</span>()
{
    <span class="pl-c">//criar layout centralizados verticalmente</span>
    lay <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateLayout</span>( <span class="pl-s"><span class="pl-pds">"</span>linear<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">"</span>VCenter,FillXY<span class="pl-pds">"</span></span> );    

    <span class="pl-c">//criar label texto e adiciona ao layout</span>
    txt <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateText</span>( <span class="pl-s"><span class="pl-pds">"</span>Medindo lux<span class="pl-pds">"</span></span> );
    <span class="pl-smi">txt</span>.<span class="pl-en">SetTextSize</span>( <span class="pl-c1">32</span> );
    <span class="pl-smi">lay</span>.<span class="pl-en">AddChild</span>( txt );
    
    <span class="pl-c">//adicionar o layout ao app    </span>
    <span class="pl-smi">app</span>.<span class="pl-en">AddLayout</span>( lay );
    
    sns <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateSensor</span>( <span class="pl-s"><span class="pl-pds">"</span>Light<span class="pl-pds">"</span></span> );
    <span class="pl-smi">sns</span>.<span class="pl-en">SetOnChange</span>( sns_OnChange );
    <span class="pl-smi">sns</span>.<span class="pl-en">Start</span>();
    <span class="pl-c1">setInterval</span>(sendToAPI, <span class="pl-c1">10000</span>);
}

<span class="pl-k">function</span> <span class="pl-en">sns_OnChange</span>( <span class="pl-smi">lux</span> )
{
  luxGlobal <span class="pl-k">=</span> lux;
}

<span class="pl-k">function</span> <span class="pl-en">sendToAPI</span>() {
  <span class="pl-k">const</span> <span class="pl-c1">http</span> <span class="pl-k">=</span> <span class="pl-k">new</span> <span class="pl-en">XMLHttpRequest</span>()
  
  <span class="pl-smi">http</span>.<span class="pl-c1">open</span>(<span class="pl-s"><span class="pl-pds">"</span>GET<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">"</span>https://api.thingspeak.com/update?api_key=NDJBSRPGPHIRZPTB&amp;field1=<span class="pl-pds">"</span></span><span class="pl-k">+</span>luxGlobal)
  <span class="pl-smi">http</span>.<span class="pl-c1">send</span>()
  <span class="pl-smi">http</span>.<span class="pl-smi">onload</span> <span class="pl-k">=</span> <span class="pl-en">setLuxText</span>(<span class="pl-smi">http</span>.<span class="pl-c1">responseText</span>, luxGlobal)
}

<span class="pl-k">function</span> <span class="pl-en">setLuxText</span>(<span class="pl-smi">resp</span>,<span class="pl-smi">lux</span>) {
    <span class="pl-smi">txt</span>.<span class="pl-en">SetText</span>( resp <span class="pl-k">+</span><span class="pl-s"><span class="pl-pds">"</span> level = <span class="pl-pds">"</span></span> <span class="pl-k">+</span> lux <span class="pl-k">+</span> <span class="pl-s"><span class="pl-pds">"</span> lux<span class="pl-pds">"</span></span> );
}</pre>
</div>
<h3><a id="user-content-passo-5---acompanhar-as-altera&ccedil;&otilde;es-na-p&aacute;gina-que-voc&ecirc;-criou-e-publicar-essa-p&aacute;gina-no-githubpages-ou-outra-plataforma-de-hospedagem-como-httpsbr000webhostcom" class="anchor" href="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2#passo-5---acompanhar-as-altera%C3%A7%C3%B5es-na-p%C3%A1gina-que-voc%C3%AA-criou-e-publicar-essa-p%C3%A1gina-no-githubpages-ou-outra-plataforma-de-hospedagem-como-httpsbr000webhostcom" aria-hidden="true"></a>Passo 5 - Acompanhar as altera&ccedil;&otilde;es na p&aacute;gina que voc&ecirc; criou e publicar essa p&aacute;gina no githubpages ou outra plataforma de hospedagem como&nbsp;<a href="https://br.000webhost.com/" rel="nofollow">https://br.000webhost.com</a>;</h3>
<p>Exemplo em execu&ccedil;&atilde;o:&nbsp;<a href="https://aquilesburlamaqui.000webhostapp.com/iot/thingspeak_android.html" rel="nofollow">https://aquilesburlamaqui.000webhostapp.com/iot/thingspeak_android.html</a></p>
