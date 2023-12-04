let estadosAFN = [];
const estadosTransicoes = {};
let inputNumEstados = null;
let inputAlfabeto = null;
let inputEstadosFinais = null;

function preecherAFN(numEstados) {
    for (let i = 0; i < numEstados; i++) {
        estadosAFN.push('q' + i);
    }
}

let form1 = document.getElementById("form1");
form1.addEventListener("submit", (e) => {
    e.preventDefault();
    inputNumEstados = document.getElementById("inputNumEstados").value;
    inputAlfabeto = (document.getElementById("inputAlfabeto").value).split(",");
    inputEstadosFinais = (document.getElementById("inputFinais").value).split(",");

    const tableAlfabeto = document.getElementById("tableAlfabeto");
    const tableEstados = document.getElementById("tableEstados");

    preecherAFN(inputNumEstados);

    let auxiliar = inputAlfabeto.map(a => {
        return `<th id="${a}">${a}</th>`;
    }).join('');
    tableAlfabeto.innerHTML += auxiliar;

    estadosAFN.forEach(q => {
        tableEstados.innerHTML += `
        <tr id="${q}">
            <td>${q}</td>`;

        let estado = document.getElementById(`${q}`);
        let inputsTransicoes = inputAlfabeto.map(a => {
            return `<td><input placeholder="{q1, q2}" type="text" id="${q}${a}"></td>`;
        }).join('');
        estado.innerHTML += inputsTransicoes;

        tableEstados.innerHTML += `
        </tr>`;
    });
});

let form2 = document.getElementById("form2");
form2.addEventListener("submit", (e) => {
    e.preventDefault();
    inputNumEstados = document.getElementById("inputNumEstados").value;
    inputAlfabeto = (document.getElementById("inputAlfabeto").value).split(",");
    inputEstadosFinais = (document.getElementById("inputFinais").value).split(",");

    estadosAFN.forEach(q => {
        const transicoes = {};

        inputAlfabeto.forEach(a => {
            const inputId = `${q}${a}`;
            const inputValue = document.getElementById(inputId).value;
            transicoes[a] = [];
            if (inputValue !== "") {
                transicoes[a] = inputValue.split(",");
            }
        });
        estadosTransicoes[q] = transicoes;
    });
});
export { inputAlfabeto, inputNumEstados, estadosAFN, inputEstadosFinais, estadosTransicoes };
