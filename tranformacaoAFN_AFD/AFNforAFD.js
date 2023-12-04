import { inputAlfabeto, inputNumEstados, estadosAFN, inputEstadosFinais, estadosTransicoes } from './forms.js';

// // Exemplo de uso
// const Q1 = ["q0", "q1", "q2", "q3"];
// const Sigma = ["a", "b", "c"];
// const transicoes = {
//     "q0": { "a": ["q1", "q2"], "c": ["q3"] },
//     "q1": { "a": ["q0"], "b": ["q0", "q1"] },
//     "q2": { "c": ["q2"] },
//     "q3": { "a": ["q2"], "b": ["q1"] },

// };
// const transicoes2 = {
//     "q0": { "a": ["q1", "q2"], "c": ["q3"] },
//     "q1": { "a": ["q0"], "b": ["q0"] },
//     "q2": { "a": ["q2"], "c": ["q2"] },
//     "q3": { "a": ["q2"], "b": ["q1"] },

// };
// //dar certo
// const transicoes3 = {
//     "q0": { "a": ["q0", "q1"] },
//     "q1": { "b": ["q2"] },
//     "q2": {},
// };
// const transicoes4 = {
//     "q0": { "a": ["q0", "q1"] },
//     "q1": { "b": ["q2", "q3", "q5"] },
//     "q2": { "a": ["q1"] },
//     "q3": { "c": ["q4"] },
//     "q4": { "c": ["q4"] },
//     "q5": { "c": ["q6"] },
//     "q6": { "d": ["q6"] }
// };
// const F1 = ["q1", "q2"];


// Verifica se um estado que possui transições não determinísticas
function hasNonDeterministicTransitions(transicoes) {
    for (const estado in transicoes) {
        for (const simbolo in transicoes[estado]) {
            if (transicoes[estado] && transicoes[estado][simbolo]) {
                if (Array.isArray(transicoes[estado][simbolo]) && transicoes[estado][simbolo].length > 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

// Retorna o estado que possui transições não determinísticas
function getNonDeterministicTransition(transicoes) {
    for (const estado in transicoes) {
        for (const simbolo in transicoes[estado]) {
            if (transicoes[estado] && transicoes[estado][simbolo]) {
                if (Array.isArray(transicoes[estado][simbolo]) && transicoes[estado][simbolo].length > 1) {
                    return { estado: estado, simbolo: simbolo, transicoes: transicoes[estado][simbolo] };
                }
            }
        }
    }
}

// Cria novo estado com o nome sendo a concatenação do conjunto de transições que o estado não determinístico possui
function createStateFromNonDetTransition(nonDetTransition) {
    // Ordenar os estados para garantir consistência
    const orderedStates = nonDetTransition.transicoes.sort();
    return orderedStates.join("");
}

// Replica as transições para o novo estado
function replaceReferencesInTransicoes(transicoes, nonDetTransition, newState) {
    // Substituindo, na tabela, todas as referências a {q21, ..., q2n} por q21...q2n;
    for (let estado of nonDetTransition.transicoes) {
        if (inputEstadosFinais.includes(estado)) {
            inputEstadosFinais.push(newState);
        }
    }
    for (const estado in transicoes) {
        for (const simbolo of inputAlfabeto) {
            if (Array.isArray(transicoes[estado][simbolo]) && transicoes[estado][simbolo].length > 1) {
                if (transicoes[estado][simbolo].sort().join("") == newState) {
                    transicoes[estado][simbolo] = [newState];
                };
            }

        }
    }
    transicoes[newState] = {};
    for (const simbolo of inputAlfabeto) {
        transicoes[newState][simbolo] = [];
        for (const estado of nonDetTransition.transicoes) {
            if (transicoes[estado][simbolo]) {
                transicoes[newState][simbolo].push(...transicoes[estado][simbolo]);
            }
        }
    }

    for (const estadomacro in transicoes) {
        for (const estadomicro in transicoes) {
            for (const simbolo in transicoes[estadomicro]) {
                if (Array.isArray(transicoes[estadomicro][simbolo])) {
                    const conjuntoTransicoes = transicoes[estadomicro][simbolo].sort().join("");
                    if (conjuntoTransicoes == estadomacro) {
                        transicoes[estadomicro][simbolo] = [estadomacro];
                    }
                }
            }
        }
    }
    return transicoes;
}



// Função principal de transformação do AFN em AFD
function transformAFNtoAFD(Q1, Sigma, transicoes, F1) {
    let Q2 = [];
    let F2 = [];
    let delta2 = {};

    // Passo 2
    Q2 = estadosAFN;
    // Passo 4
    F2 = inputEstadosFinais;

    // Passo 6
    delta2 = transicoes;
    console.log("Delta2 após Passo 6:", delta2);

    // Passo 8
    let contador = 0;
    while (hasNonDeterministicTransitions(delta2) && contador < 50) {
        const nonDetTransition = getNonDeterministicTransition(delta2);
        const newState = createStateFromNonDetTransition(nonDetTransition);
        console.log("Transição não determinística encontrada:", nonDetTransition);
        console.log("Novo estado criado:", newState);

        delta2 = replaceReferencesInTransicoes(delta2, nonDetTransition, newState);
        console.log("Delta2 após substituição:", delta2);
        contador++;
    }

    return {
        Q2: Q2,
        Sigma: Sigma,
        delta2: delta2,
        F2: inputEstadosFinais
    };
}


// ... (Código posterior)
const buttonExibir = document.getElementById("exibir");
buttonExibir.addEventListener("click", (e) => {
    const result = transformAFNtoAFD(estadosAFN, inputAlfabeto, estadosTransicoes, inputEstadosFinais);
    console.log(result);
    const divResult = document.getElementById("result");


    //exibir resultado

    divResult.innerHTML = JSON.stringify(result);
    console.log("estados finais: " + result.F2);

});
