# OIC
OIC - Omnidirecional Infrared Center

este projeto visa desenvolver uma solução centralizada para o acúmulo de diversos controles remotos de diferentes dispositivos baseados em comando infravermelho

<img src="https://contest.embarcados.com.br/wp-content/uploads/2018/08/Sem-t%C3%ADtulo-1.png" alt="" role="presentation">
https://contest.embarcados.com.br/projetos/oic-omnidirecional-infrared-center/


## mapa de funcionalidades
- Mapeamento de botões
- Controle remoto virtual
- Comando de voz
- Configurador de comando de voz
- Estatísticas de uso

## instalação de dependências 
scripts folder

## rodando o servidor
```bash
cd software/server  
npm start
```

## rodando a aplicação

```bash
cd software/front  
quasar dev -m pwa
```

informações adicionais:
atualmente possui suporte à dispositivos que utilizam o protocolo NEC
