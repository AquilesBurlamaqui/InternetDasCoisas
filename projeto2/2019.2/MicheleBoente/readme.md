construindo o relatorio com auxilio do  link https://html-online.com/editor/

<h1># Projeto 2 - Atualiza&ccedil;&atilde;o do gr&aacute;fico ThingSpeak via sensor do celular</h1>
<h3><a id="user-content-passo-1---instalar-o-app-droidscript-no-celular-android" class="anchor" href="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2#passo-1---instalar-o-app-droidscript-no-celular-android" aria-hidden="true"></a>Passo 1 - Instalar o app DroidScript no celular (android);</h3>
<p>Foi instalado o aplicativo com sucesso</p>
<h3><a id="user-content-passo-2---no-droidscript-procurar-nas-refer&ecirc;ncias-e-executar-exemplos-de-c&oacute;digos-com-sensoresex-sensor-de-luz-ou-aceler&ocirc;metro" class="anchor" href="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2#passo-2---no-droidscript-procurar-nas-refer%C3%AAncias-e-executar-exemplos-de-c%C3%B3digos-com-sensoresex-sensor-de-luz-ou-aceler%C3%B4metro" aria-hidden="true"></a>Passo 2 - No DroidScript procurar nas refer&ecirc;ncias e executar exemplos de c&oacute;digos com sensores(ex. Sensor de luz ou Aceler&ocirc;metro)</h3>
<p>Testando o codigo informado pela orienta&ccedil;&atilde;o.</p>
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
<br />
</pre>
</div>
<h3><a id="user-content-passo-3---construir-um-c&oacute;digo-no-droidscript-que-exiba-a-cada-10s-a-informa&ccedil;&atilde;o-capturada-do-sensor" class="anchor" href="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto2#passo-3---construir-um-c%C3%B3digo-no-droidscript-que-exiba-a-cada-10s-a-informa%C3%A7%C3%A3o-capturada-do-sensor" aria-hidden="true"></a>Passo 3 - Construir um c&oacute;digo no droidscript que exiba a cada 10s a informa&ccedil;&atilde;o capturada do sensor;</h3>
<p>Testando o codigo informado pela orienta&ccedil;&atilde;o.</p>
<div class="highlight highlight-source-js">
<pre>luxGlobal <span class="pl-k">=</span> <span class="pl-c1">0</span>;
<span class="pl-k">function</span> <span class="pl-en">setLuxText</span>()<br />{
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
}<br /><br /><em>* Como altera&ccedil;&atilde;o, modifiquei o codigo na linha 16 de 10000 para 3000</em><br /><br />luxGlobal <span class="pl-k">=</span> <span class="pl-c1">0</span>; <br /><span class="pl-k">function</span> <span class="pl-en">setLuxText</span>() { <br /><span class="pl-smi">txt</span>.<span class="pl-en">SetText</span>(<span class="pl-s"><span class="pl-pds">"</span> level = <span class="pl-pds">"</span></span> <span class="pl-k">+</span> luxGlobal <span class="pl-k">+</span> <span class="pl-s"><span class="pl-pds">"</span> luxGlobal<span class="pl-pds">"</span></span> <span class="pl-k">+</span>count); <br />} <br /><span class="pl-k">function</span> <span class="pl-en">OnStart</span>() <br />{ <br />lay <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateLayout</span>( <span class="pl-s"><span class="pl-pds">"</span>Linear<span class="pl-pds">"</span></span>, <span class="pl-s"><span class="pl-pds">"</span>VCenter,FillXY<span class="pl-pds">"</span></span> ); <br />txt <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateText</span>( <span class="pl-s"><span class="pl-pds">"</span><span class="pl-pds">"</span></span>, <span class="pl-c1">0.8</span>, <span class="pl-c1">0.3</span> ); <br /><span class="pl-smi">lay</span>.<span class="pl-en">AddChild</span>( txt ); <br /><span class="pl-smi">app</span>.<span class="pl-en">AddLayout</span>( lay ); <br />sns <span class="pl-k">=</span> <span class="pl-smi">app</span>.<span class="pl-en">CreateSensor</span>( <span class="pl-s"><span class="pl-pds">"</span>Light<span class="pl-pds">"</span></span> ); <br /><span class="pl-smi">sns</span>.<span class="pl-en">SetOnChange</span>( sns_OnChange ); <br /><span class="pl-smi">sns</span>.<span class="pl-en">Start</span>(); <br /><span class="pl-c1">setInterval</span>(<span class="pl-k">function</span>()<br />{ <br /><span class="pl-smi">txt</span>.<span class="pl-en">SetText</span>(<span class="pl-s"><span class="pl-pds">"</span> level = <span class="pl-pds">"</span></span> <span class="pl-k">+</span> luxGlobal <span class="pl-k">+</span> <span class="pl-s"><span class="pl-pds">"</span> luxGlobal<span class="pl-pds">"</span></span>); <br />}, <span class="pl-c1">3000</span>); <br />} <br /><span class="pl-k">function</span> <span class="pl-en">sns_OnChange</span>( <span class="pl-smi">lux</span> ) <br />{ <br /><span class="pl-c">//txt.SetText( "level = " + lux + " lux" );</span> <br />luxGlobal <span class="pl-k">=</span> lux; <br />}</pre>
</div>
<p>&nbsp;</p>
