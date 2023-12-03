import { inputAlfabeto, inputNumEstados, estadosAFN, inputEstadosFinais, estadosTransicoes } from './forms.js';

// Verifica se um estado que possui transições não determinísticas
function hasNonDeterministicTransitions(transicoes) {
    for (const estado in transicoes) {
        for (const simbolo in transicoes[estado]) {
            if (Array.isArray(transicoes[estado][simbolo]) && transicoes[estado][simbolo].length > 1) {
                return true;
            }
        }
    }
    return false;
}

// Retorna o estado que possui transições não determinísticas
function getNonDeterministicTransition(transicoes) {
    for (const estado in transicoes) {
        for (const simbolo in transicoes[estado]) {
            if (Array.isArray(transicoes[estado][simbolo]) && transicoes[estado][simbolo].length > 1) {
                return { state: estado, simbolo: simbolo, transitions: transicoes[estado][simbolo] };
            }
        }
    }
}

// Cria novo estado com o nome sendo a concatenação do conjunto de transições que o estado não determinístico possui
function createStateFromNonDetTransition(nonDetTransition) {
    return nonDetTransition.transitions.join("");
}

// Replica as transições para o novo estado
function replaceReferencesInTransicoes(transicoes, nonDetTransition, newState) {
    for (let transicao of nonDetTransition.transitions) {
        if (!Array.isArray(transicoes[newState][nonDetTransition.simbolo])) {
            transicoes[newState][nonDetTransition.simbolo] = [];
        }
        transicoes[newState][nonDetTransition.simbolo].push(transicao);
    }
    transicoes[nonDetTransition.state][nonDetTransition.simbolo] = newState;
    return transicoes;
}

// Função principal de transformação do AFN em AFD
function transformAFNtoAFD(Q1, Sigma, transicoes, F1) {
    let Q2 = [];
    let F2 = [];
    let delta2 = {};

    // Passo 2
    for (let i = 0; i < Q1.length; i++) {
        Q2.push("q2" + i);
    }

    // Passo 4
    for (let i = 0; i < Q1.length; i++) {
        if (F1.includes(Q1[i])) {
            F2.push(Q2[i]);
        }
    }

    // Passo 6
    delta2 = transicoes;
    console.log("Delta2 após Passo 6:", delta2);

    // Passo 8
    while (hasNonDeterministicTransitions(delta2)) {
        const nonDetTransition = getNonDeterministicTransition(delta2);
        const newState = createStateFromNonDetTransition(nonDetTransition);
        delta2[newState] = {};
        console.log("Transição não determinística encontrada:", nonDetTransition);
        console.log("Novo estado criado:", newState);

        delta2 = replaceReferencesInTransicoes(delta2, nonDetTransition, newState);

        console.log("Delta2 após substituição:", delta2);
    }

    return {
        Q2: Q2,
        Sigma: Sigma,
        delta2: delta2,
        F2: F2
    };
}

// Exemplo de uso
const Q1 = ["q0", "q1", "q2", "q3"];
const Sigma = ["a", "b","c"];
const transicoes = {
    "q0": { "a": ["q1", "q2"], "c":["q3"] },
    "q1": { "a": ["q0"], "b":["q0","q1"]},
    "q2": { "c":["q2"] },
    "q3": { "a": ["q2"], "b":["q1"] },

};
const F1 = ["q1","q2"];
const buttonExibir = document.getElementById("exibir");
buttonExibir.addEventListener("click", (e) => {
    const result = transformAFNtoAFD(Q1, Sigma, transicoes, F1);
    console.log(result);
});
