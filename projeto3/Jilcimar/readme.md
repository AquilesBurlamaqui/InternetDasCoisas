# Projeto 3 - Substituição do ThingSpeak por sistema web e banco de dados

## Prints da aplicação:

- Home (Página inicial)
<p align="center"><img src="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto3/Jilcimar/prints/home.png" width="350px"></p>

- Gráfico recuperando os valores do banco de dados (salvos a partir do sensor do celular)

<p align="center"><img src="https://github.com/AquilesBurlamaqui/InternetDasCoisas/tree/master/projeto3/Jilcimar/prints/grafico.png" width="350px"></p>

## Especificações do projeto
 - Versão do PHP: 7.1

Uso do framework laravel.

## Configuração

### Instalação das dependências

Para instalar as dependências do projeto o executável do composer deve estar disponível no PATH.
Caso esse requerimento seja satisfeito, basta rodar os seguintes comandos:

```bash
$ composer update
```

### Migração para ciração do banco de dados

Os seguintes comandos devem ser executados no setup do projeto:

```bash
$ php artisan migrate
```

Caso as migrações já tenham sido executadas elas podem ser desfeitas com o seguinte comando:

```bash
$ php artisan migrate:rollback
```

### Configuração do .env

Deve existir um arquivo .env no diretório raiz do projeto. Um arquivo `.env.example é fornecido contendo as configurações
padrões do projeto.

É preciso rodar o seguinte comando para preencher o campo `APP_KEY` no `.env`.

- `php artisan key:generate`

## Organização dos arquivos do projeto
- iot_linux = Pasta do projeto feito em Laravel
- sensor_lux.js = JavaScript para executar no DroidScript

### JIlcimar da Silva Fernandes :)

