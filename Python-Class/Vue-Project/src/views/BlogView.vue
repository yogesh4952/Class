
<script setup>
const arr = [{
    title:"Hancy ko bau",
    content:"Lorem ipsum dolor sit amet consectetur adipisicing elit. Velit, explicabo at quasi possimus autem reprehenderit? Sit saepe dicta molestias adipisci dolorem dolores! Magni laudantium adipisci quidem corporis iure, enim laborum veniam. Saepe, facilis eum perspiciatis repellendus exercitationem reiciendis alias expedita magni nulla hic recusandae maxime dolore nostrum natus similique itaque ab perferendis! Exercitationem cum pariatur recusandae consequuntur eligendi repellendus velit numquam culpa nam fugiat accusamus deleniti tenetur ratione fugit nesciunt a, nisi excepturi quo ipsa doloribus expedita eius."
}]
</script>

<template>
    <div>
        {{ arr.map(element=>element.title) }}
    </div>
</template>

